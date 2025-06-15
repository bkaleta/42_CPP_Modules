/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/15 23:54:25 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "********************CORRECT TESTS!********************" << std::endl;
    try {
        Bureaucrat b1("Michal", 15);
        ShrubberyCreationForm form1("home");

        form1.beSigned(b1);
        b1.executeForm(form1);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat b2("Joahim", 42); 
        RobotomyRequestForm form2("Wallie");

        form2.beSigned(b2);
        b2.executeForm(form2);
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    try {
        Bureaucrat b3("John", 3);
        PresidentialPardonForm form3("Alice");

        form3.beSigned(b3);
        b3.executeForm(form3);

    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl<< "********************INCORRECT TESTS!********************" << std::endl;

    try
    {
        Bureaucrat b4("Incorrect", 150);
        ShrubberyCreationForm form4("...");

        form4.beSigned(b4);
        b4.executeForm(form4);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b5("Bombardiro", 150);
        RobotomyRequestForm form5("Crocodilo");

        b5.executeForm(form5);
    }
    catch(const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl<< "********************POLIMORPH********************" << std::endl;

    Bureaucrat b1("Michal", 1);

    AForm* forms[3];
    
    forms[0] = new ShrubberyCreationForm("home");
    forms[1] = new RobotomyRequestForm("Wallie");
    forms[2] = new PresidentialPardonForm("Alice");

    int i = 0;
    while (i < 3) 
    {
        try 
        {
            forms[i]->beSigned(b1);
            std::cout << "Form " << forms[i]->getName() << " signed!" << std::endl;
        } 
        catch (const std::exception &e) 
        {
            std::cout << "Error signing " << forms[i]->getName() << ": " << e.what() << std::endl;
        }
        i++;
    }

    std::cout << std::endl;
    i = 0;
    while (i < 3) 
    {
        try 
        {
            b1.executeForm(*forms[i]);
        } 
        catch (const std::exception &e) {
            std::cout << "Error executing " << forms[i]->getName() << ": " << e.what() << std::endl;
        }
        i++;
    }

    std::cout << std::endl;

    i = 0;
    while (i < 3) 
    {
        delete forms[i];
        i++;
    }

    return 0;
}