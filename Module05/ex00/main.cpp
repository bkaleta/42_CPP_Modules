/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 19:48:42 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat b0("TooHigh", 13);
	Bureaucrat b1("TooLow", 149);
	
	try
	{
		std::cout << b0 << std::endl;
		for (int i = 0; i < 15; i++)
			b0.incrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << b0 << std::endl;
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
	
	std::cout << "Additional test!" << std::endl;
	try {
		Bureaucrat b3("It's Over 9000!", 9999);
		for (int i = 0; i < 10000; i++)
			b3.incrementGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "Additional test2!" << std::endl;

	Bureaucrat* ptr = 0;
	try {
		ptr = new Bureaucrat("kekw", 69);
	} catch(Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	ptr->incrementGrade();
	std::cout << ptr->getName() << std::endl;
	delete ptr;
	
	return (0);
}