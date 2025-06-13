/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:29 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 18:35:29 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string 	_formName;
	bool				_formSigned;
	const int			_formGradeToSign;
	const int			_formGradeToExec;
public:
	AForm();
	AForm(const std::string &formName, const int formGradeToSign, const int formGradeToExec);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExec() const;
	
	void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute() const = 0;

	void execute(Bureaucrat const &executor) const;

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

	class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw() {
            return "Form is not signed!";
        }
    };

    class InsufficientGradeException : public std::exception {
    public:
        const char *what() const throw() {
            return "Bureaucrat's grade is insufficient to execute the form!";
        }
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif