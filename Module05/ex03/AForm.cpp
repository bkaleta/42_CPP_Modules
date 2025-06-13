/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:16:37 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 19:02:49 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _formName("Default"), _formSigned(false), _formGradeToSign(10), _formGradeToExec(10)
{}

AForm::AForm(const std::string &formName, const int formGradeToSign, const int formGradeToExec)
: _formName(formName), _formSigned(false), _formGradeToSign(formGradeToSign), _formGradeToExec(formGradeToExec)
{}

AForm::AForm(const AForm &other) : _formName(other._formName), _formSigned(other._formSigned), _formGradeToSign(other._formGradeToSign), _formGradeToExec(other._formGradeToExec)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_formSigned = other._formSigned;
	}
	return (*this);
}

AForm::~AForm()
{}

const std::string &AForm::getName() const
{
	return (this->_formName);
}

bool AForm::isSigned() const
{
	return (_formSigned);
}

int AForm::getGradeRequiredToSign() const
{
	return (_formGradeToSign);
}

int AForm::getGradeRequiredToExec() const
{
	return (_formGradeToExec);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _formGradeToSign)
	{
		_formSigned = true;
		std::cout << bureaucrat.getName() << " signed " << _formName << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(!_formSigned)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _formGradeToExec)
	{
		throw InsufficientGradeException();
	}
	this->execute();
}

std::ostream &operator<<(std::ostream &out, const AForm &aform)
{
	std::string signedStatus;
	
	if (aform.isSigned())
		signedStatus = "Yes";
	else
		signedStatus = "No";
		
    out << "AForm: " << aform.getName() 
        << ", Signed: " << signedStatus
        << ", Grade Required to Sign: " << aform.getGradeRequiredToSign()
        << ", Grade Required to Execute: " << aform.getGradeRequiredToExec();
    return out;
}