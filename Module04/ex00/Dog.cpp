/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:01:33 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/08 21:27:01 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
}

Dog	&Dog::operator=(const Dog &other)
{
	type = other.getType();
	std::cout << "Dog assigment operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}