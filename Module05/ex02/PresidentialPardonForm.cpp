/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:53:41 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 18:28:37 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

void PresidentialPardonForm::execute() const 
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}