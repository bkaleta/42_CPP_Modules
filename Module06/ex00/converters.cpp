/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:32:44 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/14 20:00:48 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "converters.hpp"

void printCharFromDouble(double value, bool ok) 
{
    std::cout << "char: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (!std::isfinite(value)) { std::cout << "impossible\n"; return; }
    if (value < 0.0 || value > 127.0) { std::cout << "impossible\n"; return; }
    char c = static_cast<char>(value);
    if (c < 32 || c == 127) { std::cout << "Non displayable\n"; return; }
    std::cout << "'" << c << "'\n";
}

void printIntFromDouble(double value, bool ok) 
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

void printFloatFromDouble(double value, bool ok) {
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

void printDoubleFromDouble(double value, bool ok) {
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

void printAll(double value, bool ok) 
{
    printCharFromDouble(value, ok);
    printIntFromDouble(value, ok);
    printFloatFromDouble(value, ok);
    printDoubleFromDouble(value, ok);
}

bool parseIntToDouble(const std::string& input, double &value) 
{
    char *end = 0;
    double truncated;
    double  d = std::strtod(input.c_str(), &end);
    
    if (end == 0 || *end != '\0' || std::isnan(d) || std::isinf(d)) 
		return false;
    if (d >= 0.0)
        truncated = std::floor(d);
    else
        truncated = std::ceil(d);
    
    if (d != truncated)
        return false;

    if (d < static_cast<long>(INT_MIN) || d > static_cast<long>(INT_MAX)) 
		return false;
    value = d;
    
    return true;
}

bool parseCoreToDouble(const std::string& input, double &value) 
{
    char *end = 0;
    double d = std::strtod(input.c_str(), &end);
    
    if (end == 0 || *end != '\0' || std::isnan(d) || std::isinf(d)) 
        return false;

    value = d;
    return true;
}

void convertPseudo(const std::string& input) 
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

void convertChar(const std::string& input) 
{
    char c;
    if (input.size() == 1) 
		c = input[0];
    else 
		c = input[1];
    double value = static_cast<unsigned char>(c);
    printAll(value, true);
}

void convertInt(const std::string& input) 
{
    double value = 0.0;
    bool ok = parseIntToDouble(input, value);
    printAll(value, ok);
}

void convertFloat(const std::string& input) 
{
    std::string core = input;
    if (!core.empty() && core[core.size() - 1] == 'f') 
        core = core.substr(0, core.size() - 1);
    double value = 0.0;
    bool ok = parseCoreToDouble(core, value);
    printAll(value, ok);
}

void convertDouble(const std::string& input) 
{
    double value = 0.0;
    bool ok = parseCoreToDouble(input, value);
    printAll(value, ok);
}

void impossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
