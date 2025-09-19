/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 20:00:49 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Form form("Form1", 50, 75);
        Bureaucrat bureaucrat("John", 45);
        bureaucrat.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
    
    std::cout << "XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n";

    
    try
    {
        Form form("form1", -1, 5);
        Bureaucrat michal("Michal", 0);
        michal.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "check" << std::endl;

    Form form("form_test", 1, 5);
    Bureaucrat michal("Michal_test", 100);
    michal.signForm(form);
    
    return 0;
}