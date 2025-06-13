/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:03:54 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 18:48:49 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Form " << getName() << " Destroyed" << std::endl;
}

void ShrubberyCreationForm::execute() const
{
	std::ofstream outfile((_target + "_shrubbery").c_str());

	if (!outfile)
	{
		std::cout << "Error: Creating file failed" << std::endl;
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

    std::cout << "Shrubbery created at " << _target << "_shrubbery" << std::endl;
}