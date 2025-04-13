/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:47 by bkaleta           #+#    #+#             */
/*   Updated: 2025/04/13 22:30:17 by bkaleta          ###   ########.fr       */
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
	Animal *a;
	Dog	dog;
	Cat	cat;

	a = &dog;
	a->makeSound();
	a = &cat;
	a->makeSound();

	Animal *pets[2];
	pets[0] = new Dog();
	pets[1] = new Cat();
	
	int i = 0;
	while (i < 2)
	{
		pets[i]->makeSound();
		i++;
	}
	i = 0;
	while (i < 2)
	{
		delete pets[i];
		i++;
	}
	// Animal nochance;
	// nochance.makeSound();
	return (0);
}

