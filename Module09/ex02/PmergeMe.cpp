/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:11:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/10/17 14:45:27 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cerrno>
#include <iomanip>
#include <utility>
#include <algorithm>

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
	double usV = static_cast<double>(endVectorTimer - startVectorTimer) * 1e6 /  CLOCKS_PER_SEC;

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
	if (v <= 0 || v > INT_MAX) 
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

static void ford_johnson_sort_for_vector(std::vector<int> &a) {
	if (a.size() < 2)
		return ;
	
	std::vector<int> big;
	big.reserve(a.size() / 2);
	std::vector<int> small;
	small.reserve(a.size() / 2);

	for (std::size_t i = 0; i < a.size(); i+=2) {
		if (i + 1 == a.size())
			small.push_back(a[i]);
		else if (a[i] > a[i + 1]) {
			big.push_back(a[i]);
			small.push_back(a[i+1]);
		}
		else {
			big.push_back(a[i+1]);
			small.push_back(a[i]);
		}
	}
	ford_johnson_sort_for_vector(big);

	const std::size_t m = small.size();
	if (m) {
		std::vector<std::size_t> order;
		order.reserve(m);
		order.push_back(0);
		if (m > 1) {
			std::size_t j_prev = 1;
			std::size_t j_curr = 1;
			for (;;) {
				std::size_t next  = j_curr + 2 * j_prev;
				std::size_t start = (next < m) ? next : m;
				for (std::size_t r = start; r > j_curr; --r)
					order.push_back(r - 1);
				if (next >= m) break;
				j_prev = j_curr; j_curr = next;
			}
		}

		for (std::size_t t = 0; t < order.size(); ++t) {
			const std::size_t idx = order[t];
			const int x = small[idx];

			std::size_t lo = 0, hi = big.size();
			while (lo < hi) {
				std::size_t mid = lo + (hi - lo) / 2;
				if (big[mid] < x) lo = mid + 1;
				else              hi = mid;
			}
			big.insert(big.begin() + static_cast<std::ptrdiff_t>(lo), x);
		}
	}

	a = big;
}

// ################################ Deque ################################

static void ford_johnson_sort_for_deque(std::deque<int> &d) {
	if (d.size() < 2)
		return ;
	
	std::deque<int> big;
	std::deque<int> small;

	for (std::size_t i = 0; i < d.size(); i+=2) {
		if (i + 1 == d.size())
			small.push_back(d[i]);
		else if (d[i] > d[i + 1]) {
			big.push_back(d[i]);
			small.push_back(d[i+1]);
		}
		else {
			big.push_back(d[i+1]);
			small.push_back(d[i]);
		}
	}
	ford_johnson_sort_for_deque(big);

	 const std::size_t m = small.size();
    if (m) {
        std::vector<std::size_t> order;
        order.reserve(m);
        order.push_back(0);
        if (m > 1) {
            std::size_t j_prev = 1;
            std::size_t j_curr = 1;
            for (;;) {
                std::size_t next  = j_curr + 2 * j_prev;
                std::size_t start = (next < m) ? next : m;
                for (std::size_t r = start; r > j_curr; --r)
                    order.push_back(r - 1);
                if (next >= m) break;
                j_prev = j_curr; j_curr = next;
            }
        }

        for (std::size_t t = 0; t < order.size(); ++t) {
            const int x = small[ order[t] ];
            std::size_t lo = 0, hi = big.size();
            while (lo < hi) {
                std::size_t mid = lo + (hi - lo) / 2;
                if (big[mid] < x) lo = mid + 1;
                else              hi = mid;
            }
            big.insert(big.begin() + static_cast<std::ptrdiff_t>(lo), x);
        }
    }

	d.assign(big.begin(), big.end());
}
