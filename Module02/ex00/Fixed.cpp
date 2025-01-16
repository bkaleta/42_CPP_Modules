/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:14 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/16 22:01:24 by bkaleta          ###   ########.fr       */
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

Fixed& Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(other.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{ 
    std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fix_nbr);
}

void Fixed::setRawBits(int const raw)
{
	this->fix_nbr = raw;
}