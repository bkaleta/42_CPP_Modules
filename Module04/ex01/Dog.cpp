/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 20:01:33 by bkaleta           #+#    #+#             */
/*   Updated: 2025/04/13 21:55:15 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	type = other.type;
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
		type = other.type;
		std::cout << "Dog assignment operator called" << std::endl;
	}
	return (*this);
}

Dog::~Dog()
{
	delete	brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WOOF" << std::endl;
}

void Dog::setBrainIdea(int index, const std::string& idea) 
{
    brain->setIdea(index, idea);
}

std::string Dog::getBrainIdea(int index) const 
{
    return (brain->getIdea(index));
}

Brain *Dog::getBrainAddress() const 
{
    return brain;
}
