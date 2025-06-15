/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:29 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/15 22:17:35 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string 	_formName;
	bool				_formSigned;
	const int			_formGradeToSign;
	const int			_formGradeToExec;
public:
	Form();
	Form(const std::string &formName, const int formGradeToSign, const int formGradeToExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExec() const;
	
	void beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif