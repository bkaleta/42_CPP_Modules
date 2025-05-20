/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:19 by bkaleta           #+#    #+#             */
/*   Updated: 2025/05/20 20:55:57 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(10)
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) 
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) 
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other) 
{
    if (this != &other) 
        this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat died" << std::endl;
}
std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	_grade--;
	std::cout << "After increse: " << this->getGrade() << std::endl;
	if (_grade < 1)
	{
		_grade++;
		throw GradeTooHighException();
	}
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	std::cout << "Decrese increse: " << this->getGrade() << std::endl;
	if (_grade > 150)
	{
		_grade--;
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}
