/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/16 12:20:38 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("null") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execAction(Bureaucrat const &executor) const
{
	(void)executor;
	srand(time(0));
	std::cout << "Some Drilling Noises" << std::endl;
	
	if (rand() % 2)
	{
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << _target << "'s robotomy failed!" << std::endl;
	}
}