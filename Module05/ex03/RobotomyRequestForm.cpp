/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 18:24:41 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

void RobotomyRequestForm::execute() const
{
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