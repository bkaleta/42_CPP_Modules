/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:26:58 by bkaleta           #+#    #+#             */
/*   Updated: 2024/12/15 14:02:50 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact			array[8];
	int				pos, index;
public:
	PhoneBook();
	void	Add();
	void	Search();
	void	Exit();
};

#endif