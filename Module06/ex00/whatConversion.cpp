/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatConversion.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:11:40 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/10 19:39:05 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isPseudo (const std::string&);
bool isChar   (const std::string&, size_t&);
bool isInt    (const std::string&, size_t&);
bool isFloat  (const std::string&, size_t&, size_t dotpos);
bool isDouble (const std::string&, size_t&, size_t dotpos);

ConversionType whatConversion(const std::string &input, size_t &len)
{
	if (input.empty())
		return INVALID_T;
	
	if (isPseudo(input))
		return PSEUDO_T;
	
	size_t	dotpos = input.find('.');
	size_t	fpos = input.find('f');

	if (isChar(input, len))
		return CHAR_T;
	
	if (dotpos == std::string::npos)
	{
		if (isInt(input, len))
			return INT_T;
		return INVALID_T;
	}

	if (fpos != std::string::npos && fpos == input.size() - 1) {
        if (isFloat(input, len, dotpos))
            return FLOAT_T;
        return INVALID_T;
    }

    if (fpos == std::string::npos) {
        if (isDouble(input, len, dotpos))
            return DOUBLE_T;
        return INVALID_T;
    }

    return INVALID_T;
}

bool isPseudo(const std::string &input)
{
    if (input == "nan"  || input == "nanf" 
		|| input == "-inf" ||  input == "inf"  || input == "+inf" 
		|| input == "-inff"|| input == "inff"  || input == "+inff") 
		return true;
    return false;
}

bool isChar(const std::string &input, size_t &len)
{
	len = input.size();

	if (len == 1) 
	{
		unsigned char c = static_cast<unsigned char>(input[0]);
		if (!std::isdigit(c))
			return true;
	}

	if (len == 3 && input[0] == '\'' && input[2] == '\'') 
	{
		unsigned char c = static_cast<unsigned char>(input[1]);
		if (!std::isdigit(c))
			return true;
	}
	return false;
}

bool isInt(const std::string &input, size_t &len)
{
	len = input.size();
	if (len == 0) 
		return false;

	size_t i = 0;
	if (input[i] == '+' || input[i] == '-') 
	{
		if (len == 1) 
			return false;
		++i;
	}
	while (i < len) 
	{
		unsigned char c = static_cast<unsigned char>(input[i]);
		if (!std::isdigit(c))
			return false;
		++i;
	}
	return true;
}

bool isFloat(const std::string &input, size_t &len, size_t dotpos)
{
	len = input.size();
	if (len < 2)
		return false;
	if (input[len - 1] != 'f')
		return false;

	std::string core = input.substr(0, len - 1);

	if (dotpos == std::string::npos || dotpos >= core.size())
		return false;
	if (core[dotpos] != '.') 
		return false;
	if (core.find('.', dotpos + 1) != std::string::npos)
		return false;

	size_t i = 0;
	if (core[i] == '+' || core[i] == '-') 
	{
		if (core.size() == 1) 
			return false;
		++i;
	}

	bool hasDigit = false;
	while (i < core.size()) 
	{
		char c = core[i];
		if (c == '.') 
		{
			++i;
			continue;
		}
		unsigned char uc = static_cast<unsigned char>(c);
		if (!std::isdigit(uc))
			return false;
		hasDigit = true;
		++i;
	}
	return hasDigit;
}

bool isDouble(const std::string &s, size_t &len, size_t dotpos)
{
	len = s.size();
	if (len < 2) 
		return false;
	if (s[len - 1] == 'f')
		return false;

	if (dotpos == std::string::npos) 
		return false;
	if (s.find('.', dotpos + 1) != std::string::npos)
		return false;

	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') {
		if (len == 1) 
			return false;
		++i;
	}

	bool hasDigit = false;
	while (i < s.size()) 
	{
		char c = s[i];
		if (c == '.') 
		{
			++i;
			continue;
		}
		unsigned char uc = static_cast<unsigned char>(c);
		if (!std::isdigit(uc))
			return false;
		hasDigit = true;
		++i;
	}
	return hasDigit;
}