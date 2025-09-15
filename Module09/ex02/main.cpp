/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:10:18 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/15 21:59:36 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av) {
	try {
		PmergeMe myPmergeMe(ac, av);
		myPmergeMe.startPmergeMe();
	} catch (PmergeMe::MyErrorException &error) {
		std::cerr << error.what() << std::endl;
	}
}