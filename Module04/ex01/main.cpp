/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:28 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/09 19:29:28 by bkaleta          ###   ########.fr       */
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
	
	std::cout << "\nDESTRUCTORS \n\n";
	delete meta;
	delete i;
	delete j;
	delete wrong;
	
	return 0;
}
