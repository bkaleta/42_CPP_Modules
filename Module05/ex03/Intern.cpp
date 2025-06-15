/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:19:31 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/15 20:51:20 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
	typedef AForm* (Intern::*FormCreator)(const std::string &target);
	FormCreator creators[3] = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm};
	const std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = 0;
	while (i < 3 && formTypes[i] != formName)
		i++;
	if (i == 3)
	{
		std::cout << "Error: Wrong Form Name" << std::endl << " acceptable are 'shrubbery creation', 'robotomy request' or 'presidential pardon'" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << formName << std::endl;
	return (this->*creators[i])(target);
}

AForm* Intern::createShrubberyForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}
