/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:24:01 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 21:37:57 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <exception>
#include <algorithm>

Span::Span() : _N(42) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const &other) {
	*this = other;
}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	if (this != &other) {
		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return (*this);
}

void Span::addNumber(int n) {
	unsigned int size = _numbers.size();
	if (size >= _N)
		throw "Exception: Full";
	_numbers.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator first, std::vector<int>::iterator last) {
	while (first != last) {
		addNumber(*first);
		first++;
	}
}

unsigned int Span::shortestSpan() {
	if (_numbers.size() <= 1)
		throw "Exception: no numbers stored, or only one, no span can be found";
	std::vector<int> temp = _numbers;
	std::vector<int>::iterator first = temp.begin();
	std::vector<int>::iterator last = temp.end();
	std::sort(first, last);
	
	unsigned int minimum = temp[1] - temp[0];
	
	for (unsigned int i = 1; i < temp.size(); i++)
		if (static_cast<unsigned int>(temp[i] - temp[i - 1]) < minimum)
			minimum = temp[i] - temp[i - 1];
	
	return (minimum);
}

unsigned int Span::longestSpan() {
	if (_numbers.size() <= 1)
		throw "no numbers stored, or only one, no span can be found";
	std::vector<int>::iterator first = _numbers.begin();
	std::vector<int>::iterator last = _numbers.end();
	
	unsigned int max = *std::max_element(first, last);
	unsigned int min = *std::min_element(first, last);
	
	unsigned int longest = max - min;
	return (longest);
}

void Span::getAll() {
	std::cout << "Size: " << _numbers.size() << std::endl;
	std::cout << "Max Size: " << _numbers.max_size() << std::endl;
	std::cout << "Capacity: " << _numbers.capacity() << std::endl;
}

std::vector<int> Span::getNumbers() {
	return (this->_numbers);
}

