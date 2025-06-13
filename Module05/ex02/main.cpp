/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/13 12:55:31 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        AForm form("Form1", 50, 75);
        Bureaucrat bureaucrat("John", 45);
        bureaucrat.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
    
    std::cout << "XDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\n";

    AForm form("form1", -1, 5);
    Bureaucrat michal("Michal", 42);
    
    try
    {
        michal.signForm(form);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}