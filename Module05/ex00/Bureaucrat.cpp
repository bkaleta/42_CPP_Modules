/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:19 by bkaleta           #+#    #+#             */
/*   Updated: 2025/05/20 18:35:36 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
	if (_grade < 1)
		// grade is too high
	else if (_grade > 150)
		// grade is to low
	else
		// git
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat died" << std::endl;
}