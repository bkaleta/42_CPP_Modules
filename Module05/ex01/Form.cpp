/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:37 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/15 22:47:28 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _formName("Default"), _formSigned(false), _formGradeToSign(10), _formGradeToExec(10) {}

Form::Form(const std::string &formName, const int formGradeToSign, const int formGradeToExec)
: _formName(formName), _formSigned(false), _formGradeToSign(formGradeToSign), _formGradeToExec(formGradeToExec)
{
	if (this->_formGradeToSign < 1)
		throw (Form::GradeTooHighException());
	else if (this->_formGradeToSign > 150)
		throw (Form::GradeTooLowException());
	if (this->_formGradeToSign < 1)
		throw (Form::GradeTooHighException());
	else if (this->_formGradeToSign > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &other) : _formName(other._formName), _formSigned(other._formSigned), _formGradeToSign(other._formGradeToSign), _formGradeToExec(other._formGradeToExec) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_formSigned = other._formSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

const std::string &Form::getName() const
{
	return (this->_formName);
}

bool Form::isSigned() const
{
	return (this->_formSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (this->_formGradeToSign);
}

int Form::getGradeRequiredToExec() const
{
	return (this->_formGradeToExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _formGradeToSign)
		_formSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	std::string signedStatus;
	if (form.isSigned())
		signedStatus = "Yes";
	else
		signedStatus = "No";
	
    out << "Form: " << form.getName() 
        << ", Signed: " << signedStatus
        << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
        << ", Grade Required to Execute: " << form.getGradeRequiredToExec();
    return out;
}

char const	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

char const	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}
