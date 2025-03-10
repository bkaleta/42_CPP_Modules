/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:11 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/17 01:40:19 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cstdio>

class Fixed
{
private:
	int							 fix_nbr;
	static const int 			bits = 8;
public:
	Fixed(); // default constructor
	Fixed(const Fixed &other); // copy constructor
	Fixed &operator = (const Fixed &other); // copy operator
	~Fixed(); // desctructor 
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif