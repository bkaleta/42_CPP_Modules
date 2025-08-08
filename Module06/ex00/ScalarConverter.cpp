/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:04:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/08 22:39:30 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) {}
ScalarConverter::~ScalarConverter() {}

static void impossible();
static bool isPseudoLiteral(const std::string&);

void ScalarConverter::convert(const std::string& input)
{
	if (input.empty())
	{
		impossible();
		return ;
	}
	
	if (isPseudoLiteral(input))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		
		if (input == "nan" || input == "nanf")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (input == "inf" || input == "inff" || input == "+inf" || input == "+inff")
		{
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
		}
		else if (input == "-inf" || input == "-inff")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return ;
	}
	// if input is char
	// if input is digit
	// if input is float
	// if input is double
	
}

static void impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

static bool isPseudoLiteral(const std::string& input)
{
	return (input == "nan" || input == "nanf"
			|| input == "inff" || input == "-inff" || input == "+inff"
			|| input == "inf" || input == "-inf" || input == "+inf");
}
