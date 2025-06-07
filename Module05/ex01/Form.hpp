/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:29 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/08 00:49:53 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORMHPP

# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string 	_formName;
	bool				_formSigned;
	const int			_formGradeToSign;
	const int			_formGradeToExec;
public:
	Form();
	Form(const std::string &formName, bool formSinged, const int formGradeToSign, const int formGradeToExec);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	std::string getName() const;
	bool getFormSinged() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	

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

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif