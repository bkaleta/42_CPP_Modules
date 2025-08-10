/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:04:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/10 19:56:54 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
ScalarConverter::~ScalarConverter() {}

static void impossible();

void ScalarConverter::convert(const std::string& input)
{
	size_t	len = input.length();
	ConversionType		conversion = whatConversion(input, len);

	if (conversion == INVALID_T)
	{
		impossible();
		return ;	
	}
	else if (conversion == PSEUDO_T)
		std::cout << "PseudoLiteral" << std::endl;// PseudoLiteral
	else if (conversion == CHAR_T)
		std::cout << "charConversion" << std::endl; // charConversion
	else if (conversion == INT_T)
		std::cout << "intConversion" << std::endl; // intConversion
	else if (conversion == FLOAT_T)
		std::cout << "floatConversion" << std::endl; // floatConversion
	else if (conversion == DOUBLE_T)
		std::cout << "doubleConversion" << std::endl; // doubleConversion
	else
		std::cout << "Error" << std::endl; // error
}

void impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
