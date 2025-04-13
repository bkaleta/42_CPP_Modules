/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:28 by bkaleta           #+#    #+#             */
/*   Updated: 2025/04/13 22:03:32 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main()
{
	std::cout << "BASIC SUBJECT TEST" << std::endl;
	std::cout << "________________________________" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	
	delete j;
	delete i;
	std::cout << "________________________________" << std::endl;
	
	Animal* animals[6];
	int index = 0;
	
	while (index < 3) 
	{
		animals[index] = new Dog();
		std::cout << index + 1 << ". Dog" << std::endl;
		++index;
	}
	
	while (index < 6) 
	{
		animals[index] = new Cat();
		std::cout << index + 1 << ". Cat" << std::endl;
		++index;
	}
	std::cout << "________________________________" << std::endl;
	std::cout << "             Test" << std::endl;
	std::cout << "________________________________" << std::endl;
	index = 0;
	while (index < 6) 
	{
		std::cout << "Animal " << index + 1 << " type: " << animals[index]->getType() << std::endl;
		animals[index]->makeSound();
		++index;
	}
	index = 0;
	while (index < 6) 
	{
		delete animals[index];
		++index;
	}
	// Deep Copy test
	Animal *ptr;
	Dog d1;
	Dog d2;
	Cat	c1;
	Cat c2;
	d1.setBrainIdea(0, "Dog's first idea");
	d1.setBrainIdea(42, "<3");
	
	d2 = d1;
	std::cout << "________________________________" << std::endl;
	Dog d3 = d1;
	std::cout << "________________________________" << std::endl;
	d2.setBrainIdea(0, "Dog's second idea");
	std::cout << "d1's idea: " << d1.getBrainIdea(42) << std::endl;
	std::cout << "d2's idea: " << d2.getBrainIdea(42) << std::endl;
	std::cout << "d3's idea: " << d3.getBrainIdea(42) << std::endl;
	std::cout << "d1 brain addr: " << d1.getBrainAddress() << std::endl;
	std::cout << "d2 brain addr: " << d2.getBrainAddress() << std::endl;
	std::cout << "d2 brain addr: " << d3.getBrainAddress() << std::endl;
	std::cout << "c1 brain addr: " << c1.getBrainAddress() << std::endl;
	std::cout << "c2 brain addr: " << c2.getBrainAddress() << std::endl;
	ptr = &c1;
	std::cout << "ptr points to: " << ptr->getType() << std::endl;
	ptr = &d1;
	std::cout << "ptr points to: " << ptr->getType() << std::endl;
	
	return (0);
}
