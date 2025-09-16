/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:11:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/16 21:20:30 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cerrno>

bool isEmpty(const char *s);
bool isWhitespaceOnly(const char *s);
bool tryParsePositiveInt(const char *s, int &out);
static void build_jacobsthal_order(std::size_t m, std::vector<std::size_t> &order);
static void insert_before_partner(std::vector<int> &chainVal,
									std::vector<int> &chainId,
									std::size_t partnerPos,
									int value, int id);
static void ford_johnson_sort_for_vector(std::vector<int> &a);
static void ford_johnson_sort_for_deque(std::deque<int> &a);

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other) 
	: myVector(other.myVector), myDeque(other.myDeque) {}
	
PmergeMe::PmergeMe(int ac, char **av) {
	if (ac <= 1)
		throw MyErrorException("Error: provide at least one integer argument");

	for (int i = 1; i < ac; ++i) {
		const char *arg = av[i];
		if (isEmpty(arg) || isWhitespaceOnly(arg)) 
			continue;

		int value = 0;
		if (!tryParsePositiveInt(arg, value))
			throw MyErrorException(std::string("Error: invalid integer '") + (arg ? arg : "(null)") + "'");

		myVector.push_back(value);
		myDeque.push_back(value);
	}

	if (myVector.empty())
		throw MyErrorException("Error: no valid integers provided");
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other) {
		myVector = other.myVector;
		myDeque  = other.myDeque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::startProgram(int ac, char** args) {
	if (!PmergeMe::isArgumentCount(ac)) {
		std::cout << "Error: example argument ./PmergeMe 3 5 9 7 4" << std::endl;
		return ;
	}
	try {
		PmergeMe myPmergeMe(ac, args);
		myPmergeMe.startPmergeMe();
	} catch (PmergeMe::MyErrorException &error) {
		std::cerr << error.what() << std::endl;
	}
}

bool PmergeMe::isArgumentCount(int ac) {
	return ac > 1;
}

void PmergeMe::startPmergeMe() {
	// VECTOR
	printBefore();
	clock_t startVectorTimer = std::clock();
	ford_johnson_sort_for_vector(myVector);
	clock_t endVectorTimer = std::clock();
	double msV = (double)(endVectorTimer - startVectorTimer) * 1000.0 / CLOCKS_PER_SEC;

	// DEQUE
	clock_t startDequeTimer = std::clock();
	ford_johnson_sort_for_deque(myDeque);
	clock_t endDequeTimer = std::clock();
	double msD = (double)(endDequeTimer - startDequeTimer) * 1000.0 / CLOCKS_PER_SEC;
	printAfter(msV, msD);
}

void PmergeMe::printAfter(double &msV, double &msD) const {
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it) {
		if (it != myVector.begin()) std::cout << ' ';
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << myVector.size()
				<< " elements with std::vector : " << msV << " ms\n";
	std::cout << "Time to process a range of " << myDeque.size()
				<< " elements with std::deque  : " << msD << " ms\n";
}

static void build_jacobsthal_order(std::size_t m, std::vector<std::size_t> &order) {
	order.clear();
	if (m == 0u) 
		return;
	order.push_back(0u);
	std::vector<std::size_t> J;
	J.push_back(0u); 
	J.push_back(1u);
	for (std::size_t k = 2u; ; ++k) {
		std::size_t next = J[k-1] + 2u * J[k-2];
		J.push_back(next);
		if (next >= m) 
			break;
	}
	for (std::size_t k = 2u; k < J.size(); ++k) {
		std::size_t start = (J[k] < m) ? J[k] : m;
		for (std::size_t r = start; r > J[k-1]; --r) 
			order.push_back(r - 1u);
		if (J[k] >= m) 
			break;
	}
}

static void insert_before_partner(std::vector<int> &chainVal,
									std::vector<int> &chainId,
									std::size_t partnerPos,
									int value, int id)
{
	std::vector<int>::iterator b = chainVal.begin();
	std::vector<int>::iterator e = b + static_cast<std::vector<int>::difference_type>(partnerPos);
	std::vector<int>::iterator it = std::lower_bound(b, e, value);
	std::size_t pos = static_cast<std::size_t>(it - b);
	chainVal.insert(chainVal.begin() + pos, value);
	chainId .insert(chainId .begin() + pos, id);
}

// --- Ford–Johnson: wersja in-place dla std::vector<int> ---
static void ford_johnson_sort_for_vector(std::vector<int> &myVector) {
	const std::size_t n = myVector.size();
	if (n < 2u) 
		return;

	const bool hasLoneNum = (n % 2u) == 1u;
	const int  loneNum    = hasLoneNum ? myVector[n - 1u] : 0;

	std::vector<int> ps, pb, pid; // small/big/id par
	ps.reserve(n/2u); 
	pb.reserve(n/2u); 
	pid.reserve(n/2u);

	std::size_t id = 0u;
	for (std::size_t i = 0u; i + 1u < n; i += 2u, ++id) {
		int x = myVector[i], y = myVector[i+1u];
		if (x > y) { 
			int t = x; x = y; y = t; 
		}
		ps.push_back(x); 
		pb.push_back(y);
		pid.push_back(static_cast<int>(id));
	}

	// stabilne sortowanie par po pb (insertion sort po równoległych wektorach)
	for (std::size_t i = 1u; i < pb.size(); ++i) {
		int kb = pb[i], ks = ps[i], ki = pid[i];
		std::size_t j = i;
		for (; j > 0u && pb[j-1u] > kb; --j) { 
			pb[j] = pb[j-1u]; 
			ps[j] = ps[j-1u]; 
			pid[j] = pid[j-1u]; 
		}
		pb[j] = kb; 
		ps[j] = ks; 
		pid[j] = ki;
	}

	// main chain = big; pend = small (oba z id)
	std::vector<int> chainVal; 
	chainVal.reserve(n);
	std::vector<int> chainId;  
	chainId .reserve(n);
	std::vector<int> pendVal;  
	pendVal .reserve(ps.size());
	std::vector<int> pendId;   
	pendId  .reserve(ps.size());

	for (std::size_t i = 0u; i < pb.size(); ++i) {
		chainVal.push_back(pb[i]); 
		chainId.push_back(pid[i]);
		pendVal .push_back(ps[i]); 
		pendId .push_back(pid[i]);
	}

	// wstaw pend[0] przed partnera (partner jest na pozycji 0)
	insert_before_partner(chainVal, chainId, 0u, pendVal[0], pendId[0]);

	// reszta wg kolejności Jacobsthala
	std::vector<std::size_t> order;
	build_jacobsthal_order(pendVal.size(), order);
	for (std::size_t k = 1u; k < order.size(); ++k) {
		std::size_t idx = order[k];
		const int val = pendVal[idx];
		const int idp = pendId [idx];

		// znajdź aktualną pozycję partnera
		std::size_t partnerPos = 0u;
		for (std::size_t t = 0u; t < chainId.size(); ++t) {
			if (chainId[t] == idp) { 
				partnerPos = t; 
				break; 
			}
		}
		insert_before_partner(chainVal, chainId, partnerPos, val, idp);
	}

	if (hasLoneNum) {
		std::vector<int>::iterator it = std::lower_bound(chainVal.begin(), chainVal.end(), loneNum);
		std::size_t pos = static_cast<std::size_t>(it - chainVal.begin());
		chainVal.insert(chainVal.begin() + pos, loneNum);
		chainId .insert(chainId .begin() + pos, -1);
	}
	// zwróć wynik do tego samego kontenera (in-place w sensie API)
	myVector.swap(chainVal); // a = chainVal; bez dodatkowej zewnętrznej kopii
}

// --- Ford–Johnson: wersja in-place dla std::deque<int> ---
static void ford_johnson_sort_for_deque(std::deque<int> &a) {
	const std::size_t n = a.size();
	if (n < 2u) 
		return;

	const bool hasStraggler = (n % 2u) == 1u;
	const int  straggler    = hasStraggler ? a[n - 1u] : 0;

	std::vector<int> ps, pb, pid;
	ps.reserve(n/2u); 
	pb.reserve(n/2u); 
	pid.reserve(n/2u);

	std::size_t id = 0u;
	for (std::size_t i = 0u; i + 1u < n; i += 2u, ++id) {
		int x = a[i], y = a[i+1u];
		if (x > y) { 
			int t = x; 
			x = y; 
			y = t; 
		}
		ps.push_back(x); 
		pb.push_back(y); 
		pid.push_back(static_cast<int>(id));
	}

	for (std::size_t i = 1u; i < pb.size(); ++i) {
		int kb = pb[i], ks = ps[i], ki = pid[i];
		std::size_t j = i;
		for (; j > 0u && pb[j-1u] > kb; --j) { 
			pb[j] = pb[j-1u]; 
			ps[j] = ps[j-1u]; 
			pid[j] = pid[j-1u]; 
		}
		pb[j] = kb; ps[j] = ks; pid[j] = ki;
	}

	std::vector<int> chainVal; 
	chainVal.reserve(n);
	std::vector<int> chainId;  
	chainId .reserve(n);
	std::vector<int> pendVal;  
	pendVal .reserve(ps.size());
	std::vector<int> pendId;   
	pendId  .reserve(ps.size());

	for (std::size_t i = 0u; i < pb.size(); ++i) {
		chainVal.push_back(pb[i]); 
		chainId.push_back(pid[i]);
		pendVal .push_back(ps[i]); 
		pendId .push_back(pid[i]);
	}

	insert_before_partner(chainVal, chainId, 0u, pendVal[0], pendId[0]);

	std::vector<std::size_t> order;
	build_jacobsthal_order(pendVal.size(), order);
	for (std::size_t k = 1u; k < order.size(); ++k) {
		std::size_t idx = order[k];
		const int val = pendVal[idx];
		const int idp = pendId [idx];

		std::size_t partnerPos = 0u;
		for (std::size_t t = 0u; t < chainId.size(); ++t) {
			if (chainId[t] == idp) { 
				partnerPos = t; 
				break; 
			}
		}
		insert_before_partner(chainVal, chainId, partnerPos, val, idp);
	}

	if (hasStraggler) {
		std::vector<int>::iterator it = std::lower_bound(chainVal.begin(), chainVal.end(), straggler);
		std::size_t pos = static_cast<std::size_t>(it - chainVal.begin());
		chainVal.insert(chainVal.begin() + pos, straggler);
		chainId .insert(chainId .begin() + pos, -1);
	}
	// wynik z powrotem do deque (bez tworzenia „drugiej” deque)
	a.assign(chainVal.begin(), chainVal.end());
}

bool isEmpty(const char *s) {
	return !s || *s == '\0';
}

bool isWhitespaceOnly(const char *s) {
	if (!s || *s == '\0') 
		return false;
	const unsigned char *p = reinterpret_cast<const unsigned char*>(s);
	for (; *p; ++p) {
		if (!std::isspace(*p)) 
			return false;
	}
	return true;
}

bool tryParsePositiveInt(const char *s, int &out) {
	errno = 0;
	char *end = 0;
	long v = std::strtol(s, &end, 10);

	if (errno == ERANGE || end == s || *end != '\0')
		return false;
	if (v < 0 || v > INT_MAX) 
		return false;
	out = static_cast<int>(v);
	return true;
}

void PmergeMe::printBefore() const {
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it) {
		if (it != myVector.begin()) std::cout << ' ';
		std::cout << *it;
	}
	std::cout << std::endl;
}