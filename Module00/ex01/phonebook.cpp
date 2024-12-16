/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:30:09 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/16 17:18:27 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string PhoneBook::truncate(const std::string &text, size_t width) const 
{
    if (text.length() > width)
        return text.substr(0, width - 1) + ".";
    return text;
}

PhoneBook::PhoneBook()
    : index(0), size(0) {}

void	PhoneBook::add()
{
	Contact		newContact;
	std::string fN, lN, nN, pN, dS, choice;
	
	if (size < 8)
	{
		std::cout << std::endl <<"Enter First Name: ";
		std::cin >> fN;
		newContact.setFirstName(fN);
		
		std::cout << "Enter Last Name: ";
		std::cin >> lN;
		newContact.setLastName(lN);

		std::cout << "Enter Nickname: ";
		std::cin >> nN;
		newContact.setNickname(nN);

		std::cout << "Enter Phone Number: ";
		std::cin >> pN;
		newContact.setPhoneNumber(pN);

		std::cout << "Enter Darkest Secret: ";
		std::cin >> dS;
		newContact.setDarkestSecret(dS);

		std::cout << std::endl << "Contact added succesfully!" << std::endl;
		
		array_of_contacts[size] = newContact;
		size++;
	}
	else
	{
		std::cout << std::endl << "Too many contacts, overwriting oldest contact!" << std::endl;
		std::cout << "Are you sure you want to do that?" << std::endl;
		std::cout << "Type Y/N" << std::endl;
		while (choice != "Y" || choice != "N" || choice != "y" || choice != "n")
		{
			std::cin >> choice;
			if (choice == "Y")
				break ;
			else if (choice == "N")
				return ;
			else
				std::cout << "Wrong input, Type Y/N" << std::endl;
		}
		std::cout << std::endl << "Enter First Name: ";
		std::cin >> fN;
		newContact.setFirstName(fN);
		
		std::cout << "Enter Last Name: ";
		std::cin >> lN;
		newContact.setLastName(lN);

		std::cout << "Enter Nickname: ";
		std::cin >> nN;
		newContact.setNickname(nN);

		std::cout << "Enter Phone Number: ";
		std::cin >> pN;
		newContact.setPhoneNumber(pN);

		std::cout << "Enter Darkest Secret: ";
		std::cin >> dS;
		newContact.setDarkestSecret(dS);
		
		array_of_contacts[index] = newContact;
		index = (index + 1) % 8;
		std::cout << std::endl << "Contact with index " << index - 1 << " Overwritten" << std::endl;
	}
}

void	PhoneBook::search() const
{
	int	i = 0, j;
	int ind;
	
	if (size == 0) 
	{
		std::system("clear");
        std::cout << "PhoneBook is empty. Add some contacts first!" << std::endl;
        return;
    }
	std::cout << std::endl << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

	while (i < size)
	{
		std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(array_of_contacts[i].getFirstName(), 10) << "|"
                  << std::setw(10) << truncate(array_of_contacts[i].getLastName(), 10) << "|"
                  << std::setw(10) << truncate(array_of_contacts[i].getNickName(), 10) << std::endl;
		i++;
	}

	j = i - 1;
    // Walidacja indeksu
	while (true) 
	{
		if (j == 0)
			std::cout << std::endl << "Avaiable index to enter is (" << 0 << "): ";
		else
			std::cout << std::endl << "Avaiable index to enter is (0 - " << j << "): ";
		
		if (!(std::cin >> ind) || ind < 0 || ind >= size || ind > j) 
		{
			std::cout << "Invalid input. Please enter a valid number." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		break;
	}

    std::cout << std::endl << "First Name: " << array_of_contacts[ind].getFirstName() << std::endl;
    std::cout << "Last Name: " << array_of_contacts[ind].getLastName() << std::endl;
    std::cout << "Nickname: " << array_of_contacts[ind].getNickName() << std::endl;
    std::cout << "Phone Number: " << array_of_contacts[ind].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << array_of_contacts[ind].getDarkestSecret() << std::endl;
}

void	PhoneBook::exit()
{
	std::cout << "Thank you for using my software! bye bye!" << std::endl;
}