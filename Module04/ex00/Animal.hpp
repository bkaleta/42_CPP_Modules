/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 19:52:19 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/08 21:20:40 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string	type;
public:
	Animal(); // def constructor
	Animal(std::string animalType); // constructor
	Animal(const Animal &other); // copy constructor;
	Animal &operator=(const Animal &other); // Assignement 
	virtual	~Animal();
	
	std::string getType() const;
	virtual	void	makeSound() const;
};

#endif