/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:11 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/16 21:58:12 by bkaleta          ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator = (const Fixed &other);
	~Fixed();
	int	getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif