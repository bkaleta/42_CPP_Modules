/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:37 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/12 18:40:48 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _formName("Default"), _formSigned(false), _formGradeToSign(10), _formGradeToExec(10)
{}

Form::Form(const std::string &formName, const int formGradeToSign, const int formGradeToExec)
: _formName(formName), _formSigned(false), _formGradeToSign(formGradeToSign), _formGradeToExec(formGradeToExec)
{}

Form::Form(const Form &other) : _formName(other._formName), _formSigned(other._formSigned), _formGradeToSign(other._formGradeToSign), _formGradeToExec(other._formGradeToExec)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_formSigned = other._formSigned;
	}
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
	return (_formSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (_formGradeToSign);
}

int Form::getGradeRequiredToExec() const
{
	return (_formGradeToExec);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _formGradeToSign)
	{
		_formSigned = true;
		std::cout << bureaucrat.getName() << " signed " << _formName << std::endl;
	}
	else
	{
		//std::cout << bureaucrat.getName() << " couldn't sign " << _formName << " because ";
		throw GradeTooLowException();
	}
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName() 
        << ", Signed: " << (form.isSigned() ? "Yes" : "No")
        << ", Grade Required to Sign: " << form.getGradeRequiredToSign()
        << ", Grade Required to Execute: " << form.getGradeRequiredToExec();
    return out;
}