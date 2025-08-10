/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 21:04:20 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/10 21:53:12 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) { return (*this); }
ScalarConverter::~ScalarConverter() {}

static void impossible();
static void printCharFromDouble(double var, bool ok);
static void printIntFromDouble(double var, bool ok);
static void printFloatFromDouble(double var, bool ok);
static void printDoubleFromDouble(double var, bool ok);
static void printAll(double var, bool ok);
static bool parseIntToDouble(const std::string& s, double &out);
static bool parseCoreToDouble(const std::string& s, double &out);
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

// ===============================
// 2) PRINT – jeden wspólny tor wydruku z double
// ===============================
static void printCharFromDouble(double v, bool ok) {
    std::cout << "char: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (!std::isfinite(v)) { std::cout << "impossible\n"; return; }
    if (v < 0.0 || v > 127.0) { std::cout << "impossible\n"; return; }
    char c = static_cast<char>(v);
    if (c < 32 || c == 127) { std::cout << "Non displayable\n"; return; }
    std::cout << "'" << c << "'\n";
}

static void printIntFromDouble(double v, bool ok) {
    std::cout << "int: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (!std::isfinite(v)) { std::cout << "impossible\n"; return; }
    if (v < static_cast<double>(INT_MIN) || v > static_cast<double>(INT_MAX)) {
        std::cout << "impossible\n"; return;
    }
    std::cout << static_cast<int>(v) << "\n";
}

static void printFloatFromDouble(double v, bool ok) {
    std::cout << "float: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (std::isnan(v)) { std::cout << "nanf\n"; return; }
    if (std::isinf(v)) {
        if (v > 0) std::cout << "+inff\n";
        else std::cout << "-inff\n";
        return;
    }
    float f = static_cast<float>(v);
    std::cout << std::fixed << std::setprecision(1) << f << "f\n";
}

static void printDoubleFromDouble(double v, bool ok) {
    std::cout << "double: ";
    if (!ok) { std::cout << "impossible\n"; return; }
    if (std::isnan(v)) { std::cout << "nan\n"; return; }
    if (std::isinf(v)) {
        if (v > 0) std::cout << "+inf\n";
        else std::cout << "-inf\n";
        return;
    }
    std::cout << std::fixed << std::setprecision(1) << v << "\n";
}

static void printAll(double v, bool ok) {
    printCharFromDouble(v, ok);
    printIntFromDouble(v, ok);
    printFloatFromDouble(v, ok);
    printDoubleFromDouble(v, ok);
}

// ===============================
// 3) PARSE – proste, jednolite konwersje string -> double
// ===============================
static bool parseIntToDouble(const std::string& s, double &out) {
    errno = 0;
    char *end = 0;
    long val = std::strtol(s.c_str(), &end, 10);
    if (errno != 0) return false;
    if (end == 0 || *end != '\0') return false;
    if (val < static_cast<long>(INT_MIN) || val > static_cast<long>(INT_MAX)) return false;
    out = static_cast<double>(val);
    return true;
}

static bool parseCoreToDouble(const std::string& s, double &out) {
    errno = 0;
    char *end = 0;
    double d = std::strtod(s.c_str(), &end);
    if (errno != 0) return false;
    if (end == 0 || *end != '\0') return false;
    out = d;
    return true;
}

// ===============================
// 4) CONVERT – gałązki dla typów
// ===============================
static void convertPseudo(const std::string& input) {
    // Używamy realnej wartości (NaN / ±Inf), ale format wypisywania trzymamy własny.
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

static void convertChar(const std::string& input) {
    // Obsługa "a" i "'a'": bierzemy właściwy znak i dalej idziemy wspólną ścieżką.
    char c;
    if (input.size() == 1) c = input[0];
    else c = input[1]; // "'a'" -> środkowy
    double v = static_cast<unsigned char>(c);
    printAll(v, true);
}

static void convertInt(const std::string& input) {
    double v = 0.0;
    bool ok = parseIntToDouble(input, v);
    printAll(v, ok);
}

static void convertFloat(const std::string& input) {
    // Odcięcie końcowego 'f' i parsowanie rdzenia do double:
    std::string core = input;
    if (!core.empty() && core[core.size() - 1] == 'f') {
        core = core.substr(0, core.size() - 1);
    }
    double v = 0.0;
    bool ok = parseCoreToDouble(core, v);
    printAll(v, ok);
}

static void convertDouble(const std::string& input) {
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
