/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:06 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/14 22:48:20 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook		phonebook;
	std::string		input, command;
	int				i = -1;
	
	std::cout << "Welcome to the PhoneBook! Enter a command: 1.ADD, 2.SEARCH, 3.EXIT" << std::endl; 
	while (1)
	{
		std::cin >> input;
		while (input[++i])
			command = toupper(input[i]);
		if (command == "ADD" || command == "1")
			phonebook.Add();
		else if (command == "SEARCH" || command == "2")
			phonebook.Search();
		else if (command == "EXIT" || command == "3")
		{
			phonebook.Exit(); 
			return (0);
		}
		else
			std::cout << "Wrong input, Enter a command: 1.ADD, 2.SEARCH, 3.EXIT" << std::endl;
	}
	return (0);
}