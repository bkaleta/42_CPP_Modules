/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:51:55 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 20:50:39 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **argv)
{
	if (ac == 2)
		ScalarConverter::convert(argv[1]);
	else	
		std::cout << "Gosciu uzyj normalnie ./ScalarConverter <tutaj dawaj stringa>" << std::endl;
	
	return (0);
}