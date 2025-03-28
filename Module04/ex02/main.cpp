/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:47 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/28 14:59:47 by bkaleta          ###   ########.fr       */
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
	Animal	*array[100];
	int		i = 0;

	while (i < 50)
		array[i++] = new Dog();
	while (i < 100)
		array[i++] = new Cat();
	std::cout << "\n\n\n Array created\n";
	array[42]->makeSound();
	array[96]->makeSound();

	std::cout << "\n\n\n Sounds done";
	i = 0;
	while (i < 100)
	{
        delete array[i];
		i++;		
	}
	return (0);
}

