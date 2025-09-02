/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:23:59 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/02 22:47:59 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

int main() {
	Span sp = Span(80085);
	Span test(5);

	test.addNumber(1);
	test.addNumber(2);
	
	std::vector<int> Michal;
	Michal.push_back(-2137); 
	Michal.push_back(42); 
	Michal.push_back(1337); 
	Michal.push_back(666); 
	Michal.push_back(80085); 
	Michal.push_back(69); 
	Michal.push_back(420); 
	
	std::vector<int>::iterator f = Michal.begin();
	std::vector<int>::iterator l = Michal.end();

	try {
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch(const char * error) {
		std::cerr << error << std::endl;
	}
	
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(-100);
		sp.addNumber(std::numeric_limits<int>::max());
		sp.addNumber(std::numeric_limits<int>::min());
	}
	catch (const char * error) {
		std::cerr << error << std::endl;
	}

	try {
		test.addNumber(f, l);
	}
	catch (const char * error) {
		std::cerr << error << std::endl;
	}
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> print = test.getNumbers();
	for (unsigned int i = 0; i < print.size(); i++)
		std::cout << i << ". " << print[i] << std::endl;

	return (0);
}