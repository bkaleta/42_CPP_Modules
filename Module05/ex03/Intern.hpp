/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 23:19:21 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/15 20:27:09 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();

	AForm *makeForm(const std::string &formName, const std::string &target);

private:
	AForm *createShrubberyForm(const std::string &target);
	AForm *createRobotomyForm(const std::string &target);
	AForm *createPresidentialForm(const std::string &target);
};


#endif