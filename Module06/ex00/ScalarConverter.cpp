/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:04:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/15 01:24:34 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "converters.hpp"
#include <cstdio>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input)
{
	size_t	len = input.length();
	ConversionType		conversion = whatConversion(input, len);

	if (conversion == INVALID_T) 	{ impossible();			return ; }
	if (conversion == PSEUDO_T) 	{ convertPseudo(input); return ; }
	if (conversion == CHAR_T) 		{ convertChar(input); 	return ; }
	if (conversion == INT_T)		{ convertInt(input); 	return ; }
	if (conversion == FLOAT_T)		{ convertFloat(input);	return ; }
	if (conversion == DOUBLE_T)		{ convertDouble(input); return ; }
	
	impossible();
}

