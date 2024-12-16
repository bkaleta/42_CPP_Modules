/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:29:59 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/16 17:18:51 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Konstruktor Domyslny
Contact::Contact()
    : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

// Setters
void	Contact::setFirstName(const std::string &newFirstName)
{
	first_name = newFirstName;
}	

void	Contact::setLastName(const std::string &newLastName)
{
	last_name = newLastName;
}

void	Contact::setNickname(const std::string &newNickname)
{
	nickname = newNickname;
}

void	Contact::setPhoneNumber(const std::string &newPhoneNumber)
{
	phone_number = newPhoneNumber;
}

void	Contact::setDarkestSecret(const std::string &newDarkestSecret)
{
	darkest_secret = newDarkestSecret;
}

// Getters
std::string	Contact::getFirstName() const
{
	return first_name;
}
std::string	Contact::getLastName() const
{
	return last_name;
}
std::string	Contact::getNickName() const
{
	return nickname;
}
std::string	Contact::getPhoneNumber() const
{
	return phone_number;
}
std::string	Contact::getDarkestSecret() const
{
	return darkest_secret;
}