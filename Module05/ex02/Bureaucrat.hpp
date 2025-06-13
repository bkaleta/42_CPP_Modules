/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:16 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 18:44:24 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
protected:
	const std::string 	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();
	void signForm(AForm &aform);
	void executeForm(AForm const &form) const;
	

	class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Grade too high!");
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Grade too low!");
        }
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif 