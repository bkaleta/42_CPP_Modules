/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:04:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/14 18:20:45 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
ScalarConverter::~ScalarConverter() {}

static void impossible();
static void printCharFromDouble(double value, bool ok);
static void printIntFromDouble(double value, bool ok);
static void printFloatFromDouble(double value, bool ok);
static void printDoubleFromDouble(double value, bool ok);
static void printAll(double value, bool ok);
static bool parseIntToDouble(const std::string& input, double &value);
static bool parseCoreToDouble(const std::string& input, double &value);
static void convertPseudo(const std::string& input);
static void convertChar(const std::string& input);
static void convertInt(const std::string& input);
static void convertFloat(const std::string& input);
static void convertDouble(const std::string& input);


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

static void printCharFromDouble(double value, bool ok) 
{
    std::cout << "char: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (!std::isfinite(value)) { std::cout << "impossible\n"; return; }
    if (value < 0.0 || value > 127.0) { std::cout << "impossible\n"; return; }
    char c = static_cast<char>(value);
    if (c < 32 || c == 127) { std::cout << "Non displayable\n"; return; }
    std::cout << "'" << c << "'\n";
}

static void printIntFromDouble(double value, bool ok) 
{
    std::cout << "int: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (!std::isfinite(value)) { std::cout << "impossible\n"; return; }
    if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX)) 
    {
        std::cout << "impossible\n"; return;
    }
    std::cout << static_cast<int>(value) << "\n";
}

static void printFloatFromDouble(double value, bool ok) {
    std::cout << "float: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (std::isnan(value)) { std::cout << "nanf\n"; return; }
    if (std::isinf(value)) {
        if (value > 0) std::cout << "+inff\n";
        else std::cout << "-inff\n";
        return;
    }
    float f = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << f << "f\n";
}

static void printDoubleFromDouble(double value, bool ok) {
    std::cout << "double: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (std::isnan(value)) { std::cout << "nan\n"; return; }
    if (std::isinf(value)) {
        if (value > 0) std::cout << "+inf\n";
        else std::cout << "-inf\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << value << "\n";
}

static void printAll(double value, bool ok) 
{
    printCharFromDouble(value, ok);
    printIntFromDouble(value, ok);
    printFloatFromDouble(value, ok);
    printDoubleFromDouble(value, ok);
}

static bool parseIntToDouble(const std::string& input, double &value) 
{
    char *end = 0;
    double truncated;
    double  d = std::strtod(input.c_str(), &end);
    
    if (end == 0 || *end != '\0' || std::isnan(d) || std::isinf(d)) return false;
    if (d >= 0.0)
        truncated = std::floor(d);
    else
        truncated = std::ceil(d);
    
    if (d != truncated)
        return false;

    if (d < static_cast<long>(INT_MIN) || d > static_cast<long>(INT_MAX)) return false;
    value = d;
    
    return true;
}

static bool parseCoreToDouble(const std::string& input, double &value) 
{
    char *end = 0;
    double d = std::strtod(input.c_str(), &end);
    
    if (end == 0 || *end != '\0' || std::isnan(d) || std::isinf(d)) 
        return false;

    value = d;
    return true;
}

static void convertPseudo(const std::string& input) 
{
    double dv;
    if (input == "nan" || input == "nanf") {
        dv = std::numeric_limits<double>::quiet_NaN();
    } else {
        bool neg = false;
        if (input == "-inf" || input == "-inff") neg = true;
        if (neg) dv = -std::numeric_limits<double>::infinity();
        else     dv =  std::numeric_limits<double>::infinity();
    }
    printAll(dv, true);
}

static void convertChar(const std::string& input) 
{
    char c;
    if (input.size() == 1) c = input[0];
    else c = input[1];
    double v = static_cast<unsigned char>(c);
    printAll(v, true);
}

static void convertInt(const std::string& input) 
{
    double v = 0.0;
    bool ok = parseIntToDouble(input, v);
    printAll(v, ok);
}

static void convertFloat(const std::string& input) 
{
    std::string core = input;
    if (!core.empty() && core[core.size() - 1] == 'f') 
        core = core.substr(0, core.size() - 1);
    double v = 0.0;
    bool ok = parseCoreToDouble(core, v);
    printAll(v, ok);
}

static void convertDouble(const std::string& input) 
{
    double v = 0.0;
    bool ok = parseCoreToDouble(input, v);
    printAll(v, ok);
}

void impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
