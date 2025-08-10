/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:04:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/10 17:43:36 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <iomanip>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
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
		float	fvar;
		double	dvar;
		bool	negative_value = false;
		
		if (input == "nan" || input == "nanf")
		{
			fvar = std::numeric_limits<float>::quiet_NaN();
			dvar = std::numeric_limits<double>::quiet_NaN();
		}
		else
		{
			if (input == "-inf" || input == "-inff")
				negative_value = true;
				
			if (negative_value)
			{
				fvar = -std::numeric_limits<float>::infinity();
				dvar = -std::numeric_limits<double>::infinity();
			}
			else
			{
				fvar = std::numeric_limits<float>::infinity();
				dvar = std::numeric_limits<double>::infinity();
			}
		}
		
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;

		if (std::isnan(fvar))
			std::cout << "float: " << fvar << std::endl;
		else if (std::isinf(fvar))
		{
			if (fvar > 0)
				std::cout << "float: " << fvar << std::endl;
			else
				std::cout << "float: " << fvar << std::endl;
		}
		else
			std::cout << std::fixed << std::setprecision(1) << fvar << "f" << std::endl;
		return ;
	}
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
