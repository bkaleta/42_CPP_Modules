/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:00:13 by bkaleta           #+#    #+#             */
/*   Updated: 2025/04/13 21:58:49 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	type = "Cat";
	brain = new Brain(*other.brain);
	std::cout << "Cat copy consturctor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
		std::cout << "Cat assignment operator called" << std::endl;
	}
	return (*this);
}

Cat::~Cat()
{
	delete	brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meeeeeeow" << std::endl;
}

void Cat::setBrainIdea(int index, const std::string& idea) 
{
    brain->setIdea(index, idea);
}

std::string Cat::getBrainIdea(int index) const 
{
    return brain->getIdea(index);
}

Brain *Cat::getBrainAddress() const 
{
    return brain;
}
