/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:33:36 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/17 02:39:23 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstdio>
#include <cmath>

class Fixed
{
private:
	int							 fix_nbr;
	static const int 			bits = 8;
public:
	Fixed(); // default constructor
	Fixed(const Fixed &other); // copy constructor
	Fixed(const int to_fix);
	Fixed(const float to_fix);
	Fixed &operator = (const Fixed &other); // copy operator
	~Fixed(); // desctructor 
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif