#ifndef CONVERTERS_HPP
# define CONVERTERS_HPP

# include <string>
# include "ScalarConverter.hpp"

void	impossible();
void	printChar(char c, bool ok);
void	printInt(int i, bool ok);
void	printFloat(float f, bool ok);
void	printDouble(double d, bool ok);
void	convertPseudo(const std::string& input);
void	convertChar(const std::string& input);
void	convertInt(const std::string& input);
void	convertFloat(const std::string& input);
void	convertDouble(const std::string& input);
void	printAll(char c, int i, float f, double d);

#endif