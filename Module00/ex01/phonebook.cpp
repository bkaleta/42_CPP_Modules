/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:09 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/15 13:57:21 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	:	pos(0), index(0) {}
void	PhoneBook::Add()
{
	Contact		newContact;
	std::string	fn, ln, nn, p, s;
	
	std::cout << "Enter First Name: "; 		std::cin >> fn;
	std::cout << "Enter Last Name: "; 		std::cin >> ln;
	std::cout << "Enter Nickname: "; 		std::cin >> nn;
	std::cout << "Enter Phone Number: "; 	std::cin >> p;
	std::cout << "Enter Darkest Secret: "; 	std::cin >> s;

	if (pos < 8) 
	{
		newContact.SetData(fn, ln, nn, p, s);
		array[pos] = newContact;
		std::cout << std::endl << "Contact added succesfully!" << std::endl;
		pos++;
	}
	else 
	{
		
	}
}
void	PhoneBook::Search()
{
	std::cout << "test2" << std::endl;
}
void	PhoneBook::Exit()
{
	std::cout << "test3" << std::endl;
}