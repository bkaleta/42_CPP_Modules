/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:28 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/08 22:09:46 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <stdio.h>

int	main()
{
	const	Animal		*meta = new Animal();
	const	Animal		*j = new Dog();
	const	Animal		*i = new Cat();
	const	WrongAnimal	*wrong = new WrongAnimal();
	const	WrongCat	*wrongcat = new WrongCat();
	Animal	*ptr;

	std::cout << "\n" << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << "\n" << std::endl;
	
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	wrong->makeSound();
	wrongcat->makeSound();
	
	delete meta;
	delete i;
	delete j;
	delete wrong;
	delete wrongcat;
	
	return 0;
}
