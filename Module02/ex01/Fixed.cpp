/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:33:34 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/17 02:41:47 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() 
{
	fix_nbr = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	fix_nbr = other.fix_nbr;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int const to_fix)
{
	fix_nbr = to_fix << bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float to_fix)
{
	fix_nbr = roundf(to_fix * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return (out);
}

Fixed::~Fixed()
{ 
    std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->fix_nbr);
}

void Fixed::setRawBits(int const raw)
{
	this->fix_nbr = raw;
}

int	Fixed::toInt(void) const
{
	return (fix_nbr >> bits); // dzielenie na 2^8
}

float	Fixed::toFloat(void) const
{
	return ((float)fix_nbr / (1 << bits)); 
	// dzielenie na (1 * 2^8) // z (float) cpp nie ucina po przecinku
}