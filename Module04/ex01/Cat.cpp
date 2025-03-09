/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:00:13 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/08 21:16:14 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
}

Cat	&Cat::operator=(const Cat &other)
{
	type = other.getType();
	std::cout << "Cat assigment operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeeow" << std::endl;
}
