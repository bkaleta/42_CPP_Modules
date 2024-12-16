/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:06 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/16 18:45:44 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook				phonebook;
	std::string				input;
	
	std::cout << "Welcome to the PhoneBook! Enter a input: 1.ADD, 2.SEARCH, 3.EXIT" << std::endl; 
while (1)
	{
		std::cin >> input;
		
		if (input == "ADD" || input == "1")
		{
			phonebook.add();
			std::cout << std::endl << "Type one of the three following command" << std::endl;
			std::cout << "1. ADD | 2. SEARCH | 3. EXIT : ";	
		}
		else if (input == "SEARCH" || input == "2")
		{
			phonebook.search();
			std::cout << std::endl << "Type one of the three following command" << std::endl;
			std::cout << "1. ADD | 2. SEARCH | 3. EXIT : ";		
		}
		else if (input == "EXIT" || input == "3")
			break ;
		else
		{
			std::cout << std::endl << "Wrong input, try ADD, SEARCH or EXIT" << ": ";
		}
	}
	return (0);
}