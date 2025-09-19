/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:52:03 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 20:04:44 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string &target);
	PresidentialPardonForm(PresidentialPardonForm const &other);
	PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
	virtual ~PresidentialPardonForm();

	void execAction(Bureaucrat const &executor) const;
private:
	std::string _target;
};

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif