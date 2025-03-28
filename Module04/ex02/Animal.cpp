/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:53:19 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/28 14:52:47 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

 // Default constructor
Animal::Animal() 
	: type("some default animal") 
{
	std::cout << "Animal default constructor called" << std::endl;
}
// Constructor
Animal::Animal(std::string animalType)
	: type(animalType) 
{
	std::cout << "Animal " << type << " constructor called" << std::endl;
} 
// copy constructor;
Animal::Animal(const Animal &other) 
{
	*this = other;
}
// Assignement 
Animal	&Animal::operator=(const Animal &other)
{
	type = other.type;
	return (*this);
}
// Destructor
Animal::~Animal() 
{
	std::cout << "Animal destructor called" << std::endl;
}
// Get type
std::string	Animal::getType() const 
{
	return (type);
}

void	Animal::makeSound() const 
{
	std::cout << "Animal sound" << std::endl;
}