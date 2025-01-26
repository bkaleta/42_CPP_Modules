/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:33:36 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/26 01:53:11 by bkaleta          ###   ########.fr       */
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

	bool	operator > (const Fixed &other) const;
	bool	operator < (const Fixed &other) const;
	bool	operator >= (const Fixed &other) const;
	bool	operator <= (const Fixed &other) const;
	bool	operator == (const Fixed &other) const;
	bool	operator != (const Fixed &other) const;

	Fixed	operator + (const Fixed &other) const;
	Fixed	operator - (const Fixed &other) const;
	Fixed	operator * (const Fixed &other) const;
	Fixed	operator / (const Fixed &other) const;

	Fixed	operator ++ (int);
	Fixed	operator -- (int);
	Fixed	&operator ++ (void);
	Fixed	&operator -- (void);

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(Fixed const &a, Fixed const &b);
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif