/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 20:52:15 by bkaleta           #+#    #+#             */
/*   Updated: 2025/08/14 19:29:06 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER

# include <iostream>
# include <limits>
# include <cmath>
# include <cstdlib>
# include <climits>
# include <cctype>
# include <iomanip>

enum ConversionType {
    INVALID_T = -1,
    PSEUDO_T  = 1,
    CHAR_T    = 2,
    INT_T     = 3,
    FLOAT_T   = 4,
    DOUBLE_T  = 5
};

class ScalarConverter
{
public:
	static void	convert(const std::string&);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();
};

ConversionType		whatConversion(const std::string &, size_t &);

#endif