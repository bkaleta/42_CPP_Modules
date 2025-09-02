/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 19:23:59 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/02 23:02:56 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>
#include <cstdlib>
#include <ctime>

int main() {
	srand(time(NULL));
	
	Span sp = Span(80085);
	Span test(123456);
	
	std::vector<int> Michal;
	
	for (unsigned int i = 0; i < 12345; i++)
		Michal.push_back(rand());
	
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
		
	std::cout << test.shortestSpan() << std::endl;
	std::cout << test.longestSpan() << std::endl;

	return (0);
}