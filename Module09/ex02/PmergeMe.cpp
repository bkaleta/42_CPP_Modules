/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:11:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/17 22:58:45 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cerrno>
#include <iomanip>
#include <utility>   // std::pair, std::make_pair
#include <algorithm> // stable_sort, lower_bound

bool isEmpty(const char *s);
bool isWhitespaceOnly(const char *s);
bool tryParsePositiveInt(const char *s, int &out);
static void ford_johnson_sort_for_vector(std::vector<int> &a);
static void ford_johnson_sort_for_deque(std::deque<int> &a);

// ############################## Canonical Form ##############################

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

// ############################## Start of Merge-Sort ##############################
void PmergeMe::startPmergeMe() {
	// VECTOR
	printBefore();
	clock_t startVectorTimer = std::clock();
	ford_johnson_sort_for_vector(myVector);
	clock_t endVectorTimer = std::clock();
	double usV = static_cast<double>(endVectorTimer - startVectorTimer) * 1e6 / CLOCKS_PER_SEC;

	// DEQUE
	clock_t startDequeTimer = std::clock();
	ford_johnson_sort_for_deque(myDeque);
	clock_t endDequeTimer = std::clock();
	double usD = static_cast<double>(endDequeTimer - startDequeTimer) * 1e6 / CLOCKS_PER_SEC;
	printAfter(usV, usD);
}

// ############################## Utils for Validation ##############################
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

// #################################### PRINTERS ####################################

void PmergeMe::printBefore() const {
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it) {
		if (it != myVector.begin()) std::cout << ' ';
		std::cout << *it;
	}
	std::cout << std::endl;
}

void PmergeMe::printAfter(double &usV, double &usD) const {
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = myVector.begin(); it != myVector.end(); ++it) {
		if (it != myVector.begin()) std::cout << ' ';
		std::cout << *it;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << myVector.size()
				<< " elements with std::vector : " << std::fixed << std::setprecision(5) << usV << " us\n";
	std::cout << "Time to process a range of " << myDeque.size()
				<< " elements with std::deque  : " << std::fixed << std::setprecision(5) << usD << " us\n";
}

// ################################ Proud of this XD ################################
bool PmergeMe::isArgumentCount(int ac) {
	return ac > 1;
}

// ############################## Merge-Sort Algorithm ##############################

static std::size_t find_partner_pos(const std::vector< std::pair<int,int> > &chain, int id) {
	for (std::size_t i = 0; i < chain.size(); ++i) 
		if (chain[i].second == id) 
			return i;
	return 0;
}

static void insert_before_partner(std::vector< std::pair<int,int> > &chain,
									std::size_t partnerPos, int val, int id) {
	std::pair<int,int> key(val, -1);
	std::vector< std::pair<int,int> >::iterator b = chain.begin();
	std::vector< std::pair<int,int> >::iterator e = b + static_cast<std::vector< std::pair<int,int> >::difference_type>(partnerPos);
	std::vector< std::pair<int,int> >::iterator it = std::lower_bound(b, e, key);
	chain.insert(it, std::make_pair(val, id));
}

static void ford_johnson_sort_for_vector(std::vector<int> &a) {
	const std::size_t n = a.size();
	if (n < 2) 
		return;

	const bool odd = (n % 2) == 1;
	const int  straggler = odd ? a[n - 1] : 0;

	std::vector< std::pair<int,int> > big;  
	big.reserve(n/2);
	std::vector<int> small_by_id;           
	small_by_id.reserve(n/2);
	for (std::size_t i = 0, id = 0; i + 1 < n; i += 2, ++id) {
		int x = a[i], y = a[i+1];
		if (x > y) { 
			int t = x; 
			x = y; 
			y = t; 
		}
		big.push_back(std::make_pair(y, static_cast<int>(id)));
		small_by_id.push_back(x);
	}

	std::stable_sort(big.begin(), big.end());

	std::vector< std::pair<int,int> > chain = big;
	std::vector< std::pair<int,int> > pend; 
	pend.reserve(big.size());
	for (std::size_t i = 0; i < big.size(); ++i) {
		int id = big[i].second;
		pend.push_back(std::make_pair(small_by_id[id], id));
	}

	insert_before_partner(chain, 0, pend[0].first, pend[0].second);

	const std::size_t m = pend.size();
	if (m > 1) {
		std::size_t j_prev = 1;
		std::size_t j_curr = 1;
		for (;;) {
			std::size_t next  = j_curr + 2 * j_prev;
			std::size_t start = (next < m) ? next : m;
			for (std::size_t r = start; r > j_curr; --r) {
				std::size_t idx = r - 1;
				int val = pend[idx].first;
				int id  = pend[idx].second;
				std::size_t partnerPos = find_partner_pos(chain, id);
				insert_before_partner(chain, partnerPos, val, id);
			}
			if (next >= m) 
				break;
			j_prev = j_curr; 
			j_curr = next;
		}
	}

	if (odd) {
		std::pair<int,int> key(straggler, -1);
		std::vector< std::pair<int,int> >::iterator it = std::lower_bound(chain.begin(), chain.end(), key);
		chain.insert(it, std::make_pair(straggler, -1));
	}

	for (std::size_t i = 0; i < chain.size(); ++i) 
		a[i] = chain[i].first;
	if (a.size() != chain.size()) a.resize(chain.size());
}

// ################################ Deque ################################

static std::size_t find_partner_pos_deque(const std::deque< std::pair<int,int> > &chain, int id) {
	for (std::size_t i = 0; i < chain.size(); ++i)
		if (chain[i].second == id) 
			return i;
    return 0;
}

static void insert_before_partner_deque(std::deque< std::pair<int,int> > &chain,
										std::size_t partnerPos, int val, int id) {
	std::pair<int,int> key(val, -1);
	std::deque< std::pair<int,int> >::iterator b = chain.begin();
	std::deque< std::pair<int,int> >::iterator e =
		b + static_cast<std::deque< std::pair<int,int> >::difference_type>(partnerPos);
	std::deque< std::pair<int,int> >::iterator it = std::lower_bound(b, e, key);
	chain.insert(it, std::make_pair(val, id));
}

static void ford_johnson_sort_for_deque(std::deque<int> &d) {
	const std::size_t n = d.size();
	if (n < 2) 
		return;

	const bool odd = (n % 2) == 1;
	const int  straggler = odd ? d[n - 1] : 0;

	std::deque< std::pair<int,int> > big;   
	big.clear();
	std::vector<int> small_by_id;          
	small_by_id.reserve(n/2);

	for (std::size_t i = 0, id = 0; i + 1 < n; i += 2, ++id) {
		int x = d[i], y = d[i+1];
		if (x > y) { 
			int t = x; 
			x = y; 
			y = t; 
		}
		big.push_back(std::make_pair(y, static_cast<int>(id)));
		small_by_id.push_back(x);
	}

	std::stable_sort(big.begin(), big.end());

	std::deque< std::pair<int,int> > chain = big;
	std::vector< std::pair<int,int> > pend; pend.reserve(big.size());
	for (std::size_t i = 0; i < big.size(); ++i) {
		int id = big[i].second;
		pend.push_back(std::make_pair(small_by_id[id], id));
	}

    insert_before_partner_deque(chain, 0, pend[0].first, pend[0].second);

	const std::size_t m = pend.size();
	if (m > 1) {
		std::size_t j_prev = 1;
		std::size_t j_curr = 1;
		for (;;) {
			std::size_t next  = j_curr + 2 * j_prev;
			std::size_t start = (next < m) ? next : m;
			for (std::size_t r = start; r > j_curr; --r) {
				std::size_t idx = r - 1;
				int val = pend[idx].first;
				int id  = pend[idx].second;
				std::size_t partnerPos = find_partner_pos_deque(chain, id);
				insert_before_partner_deque(chain, partnerPos, val, id);
			}
			if (next >= m) 
				break;
			j_prev = j_curr; j_curr = next;
		}
	}

	if (odd) {
		std::pair<int,int> key(straggler, -1);
		std::deque< std::pair<int,int> >::iterator it = std::lower_bound(chain.begin(), chain.end(), key);
		chain.insert(it, std::make_pair(straggler, -1));
	}

	for (std::size_t i = 0; i < chain.size(); ++i) 
		d[i] = chain[i].first;
	if (d.size() != chain.size()) d.resize(chain.size());
}

// test

