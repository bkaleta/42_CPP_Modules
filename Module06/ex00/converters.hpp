#ifndef CONVERTERS_HPP
# define CONVERTERS_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <iomanip>
# include <climits>
# include "ScalarConverter.hpp"

void	impossible();
void	printCharFromDouble(double value, bool ok);
void	printIntFromDouble(double value, bool ok);
void	printFloatFromDouble(double value, bool ok);
void	printDoubleFromDouble(double value, bool ok);
void	printAll(double value, bool ok);
bool	parseIntToDouble(const std::string& input, double &value);
bool	parseCoreToDouble(const std::string& input, double &value);
void	convertPseudo(const std::string& input);
void	convertChar(const std::string& input);
void	convertInt(const std::string& input);
void	convertFloat(const std::string& input);
void	convertDouble(const std::string& input);

#endif