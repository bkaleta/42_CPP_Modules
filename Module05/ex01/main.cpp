/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:13:12 by bkaleta           #+#    #+#             */
/*   Updated: 2025/06/12 18:39:27 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

    Form form("form1", -1, 5);
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