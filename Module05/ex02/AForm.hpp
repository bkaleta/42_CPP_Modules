/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:29 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/16 12:15:40 by bkaleta          ###   ########.fr       */
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
	void execute(Bureaucrat const &executor) const;

	virtual void execAction(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception 
    {
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception 
    {
        public:
            virtual const char *what() const throw();
    };

	class FormNotSignedException : public std::exception 
    {
        public:
            const char *what() const throw();
    };

    class InsufficientGradeException : public std::exception 
    {
        public:
            const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif