/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:41 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/16 12:21:01 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("null") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

void PresidentialPardonForm::execAction(Bureaucrat const &executor) const 
{
	(void)executor;
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form)
{
	return (out << form.getName() << " form, signed: " << form.isSigned() << ", sign grade: " << form.getGradeRequiredToSign() << ", exec grade: " << form.getGradeRequiredToExec());
}