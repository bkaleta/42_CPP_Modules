/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:32:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/19 20:53:56 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converters.hpp"
# include <iostream>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <climits>
# include <cctype>
# include <iomanip>

void convertPseudo(const std::string& input) 
{
    float f = 0.0f;
    double d = 0.0;

    if (input == "nan" || input == "nanf")
    {
        f = std::numeric_limits<float>::quiet_NaN();
        d = std::numeric_limits<double>::quiet_NaN();
    }
    else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff")
    {
        f = std::numeric_limits<float>::infinity();
        d = std::numeric_limits<double>::infinity();
    }
    else if (input == "-inf" || input == "-inff")
    {
        f = -std::numeric_limits<float>::infinity();
        d = -std::numeric_limits<double>::infinity();
    }

    printChar(0, false);
    printInt(0, false);
    printFloat(f, true);
    printDouble(d, true);
}

void convertChar(const std::string& input) 
{
    char c;
	
    if (input.size() == 1)
        c = input[0];
    else
        c = input[1];

    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    printAll(c, i, f, d);
}

void convertInt(const std::string& input) 
{
	double checker = std::strtod(input.c_str(), NULL);
    int i = std::atoi(input.c_str());
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

	if (checker > static_cast<double>(INT_MAX) || checker < static_cast<double>(INT_MIN) 
		|| std::isnan(checker) || std::isinf(checker))
    {
		impossible();
        return ;
    }
	printAll(c, i, f, d);
}

void convertFloat(const std::string& input) 
{
    float f = std::strtof(input.c_str(), NULL);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

	printAll(c, i, f, d);
}

void convertDouble(const std::string& input) 
{
    double d = std::strtod(input.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    printAll(c, i, f, d);
}

void printAll(char c, int i, float f, double d)
{
	bool charOverFlow = false;
	bool intOverFlow = false;

	if (d > 127 || d < 0)
		charOverFlow = true;
	if (d > INT_MAX || d < INT_MIN)
		intOverFlow = true;
	
	printChar(c, !charOverFlow);
	printInt(i, !intOverFlow);
	printFloat(f, true);
	printDouble(d, true);
}

void printChar(char c, bool ok)
{
	std::cout << "char: ";
	
	if (!ok)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (c < 32 || c == 127)
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void printInt(int i, bool ok)
{
	std::cout << "int: ";
	if (!ok)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << i << std::endl;
}

void printFloat(float f, bool ok)
{
	std::cout << "float: ";
	if (!ok)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (f == static_cast<int>(f))
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
}

void printDouble(double d, bool ok)
{
	std::cout << "double: ";
	
	if (!ok)
	{
		std::cout << "impossible";
		return ;
	}
	if (d == static_cast<int>(d))
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
	else
		std::cout << d << std::endl;
}

void impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
