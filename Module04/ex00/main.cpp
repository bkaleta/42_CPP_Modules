/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:28 by bkaleta           #+#    #+#             */
/*   Updated: 2025/04/12 00:46:55 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "CONSTRUCTORS \n\n";
	const	Animal		*meta = new Animal();
	const	Animal		*j = new Dog();
	const	Animal		*i = new Cat();
	const	WrongAnimal	*wrong = new WrongCat();

	std::cout << "\nTYPES \n\n";
	std::cout << "\n" << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << wrong->getType() << " " << std::endl;
	
	std::cout << "\nSOUNDS \n\n";
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	wrong->makeSound();
	
	std::cout << "\nOTHER APPROACH TO POLIMORPH on stack\n";
	Dog	dog;
	Cat cat;

	Animal	*ptr;
	ptr = &dog;
	std::cout << "Lets see if ptr point to proper object!\n";
	std::cout << "Type: " << ptr->getType() << std::endl;
	ptr->makeSound();

	ptr = &cat;
	std::cout << "Lets see if ptr point to proper object!\n";
	std::cout << "Type: " << ptr->getType() << std::endl;
	ptr->makeSound();

	std::cout << "\nOTHER APPROACH TO POLIMORPH on HEAP\n";
	Dog		*doggy = new Dog();
	Cat		*catty = new Cat();
	Animal	*aPTR;

	aPTR = doggy;
	aPTR->makeSound();
	aPTR = catty;
	aPTR->makeSound();
	
	
	std::cout << "\nDESTRUCTORS \n\n";
	delete meta;
	delete i;
	delete j;
	delete wrong;
	delete doggy;
	delete catty;
	
	return 0;
}
