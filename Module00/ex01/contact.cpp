/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:29:59 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/15 13:12:39 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
	:	first_name(""), last_name(""), nickname(""), phone(""), secret(""){}
void	Contact::SetData(std::string fn, std::string ln, std::string nn, std::string p, std::string s)
{
	first_name = fn;
	last_name = ln;
	nickname = nn;
	phone = p;
	secret = s;
}