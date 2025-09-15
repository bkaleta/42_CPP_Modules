/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:11:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/15 21:58:01 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &other) : myVector(other.myVector) {}

PmergeMe::PmergeMe(int ac, char **av) {
	if (ac < 2)
		throw MyErrorException("Error: Argc < 2");
	for (int i = 1; i < ac; i++) {
		int temp = std::atoi(av[i]);
		if (temp < 0)
			throw MyErrorException("Error: Negative Integer");
		myVector.push_back(temp);
		myDeque.push_back(temp);
	}
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this != &other)
		*this = other;
	return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::startPmergeMe() {
	printContent();
	clock_t startTimer = clock();

	// rozpoczynam sorotwanie dla vektora
	sortVector();
	
	clock_t middleTimer = clock();
	
	// sortowanie dla deque
	clock_t endTimer = clock();
	this->printContent();
	
	std::cout << " CZAAAAAS: \n" 
		<< startTimer << "\n"
		<< middleTimer - startTimer << "\n"
		<< endTimer - middleTimer << "\n";

	// printAll
}

//  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

// 3 5 9 7 4
// 3,5 | 9,7 | 4
// greaterNums = {4, 5, 9};
// smallerNums = {3, 7};
// 5,9 | 4;
// smallerNums2 = {5};
// greaterNums2 = {9,4};
// greaterNums2 = {4,9};
// greaterNums2 = {4,5,9};
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
// 5, 7, 8, 9, 10
// 5, 7, 8
// 5,6,7 
