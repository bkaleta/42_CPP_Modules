/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:03:54 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/16 14:49:36 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) 
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm::AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	this->_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::execAction(Bureaucrat const &executor) const
{
	(void)executor;
	std::ofstream outfile;
	
	outfile.open((this->_target + "_shrubbery").c_str()); 
	if (outfile.fail())
	{
		std::cout << "Error: Cannot Open file" << std::endl;
		return ;
	}
	outfile << "        *\n";
	outfile << "       * *\n";
	outfile << "      *   *\n";
    outfile << "     *     *\n";
    outfile << "    *       *\n";
    outfile << "   *         *\n";
    outfile << "  *           *\n";
    outfile << " * * * * * * * *\n";
    outfile << "       |||\n";
	
	outfile.close();

    std::cout << "Shrubbery created at " << _target << "_shrubbery" << std::endl;
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
	return (out << form.getName() << " form, signed: " << form.isSigned() << ", sign grade: " << form.getGradeRequiredToSign() << ", exec grade: " << form.getGradeRequiredToExec());
}