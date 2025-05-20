/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/05/20 20:53:32 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b0("TooHigh", 13);
	Bureaucrat b1("TooLow", 149);
	int i = 0;
	
	try
	{
		std::cout << b0 << std::endl;
		while (i < 15)
		{
			b0.incrementGrade();
			i++;
		}
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << b1 << std::endl;

		b1.decrementGrade();
		b1.decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << b0 << std::endl << b1 << std::endl;
	std::cout << "Done!" << std::endl;
	
	return (0);
}