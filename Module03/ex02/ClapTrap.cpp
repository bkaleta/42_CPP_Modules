/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:19 by bkaleta           #+#    #+#             */
/*   Updated: 2025/02/13 23:27:04 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default ClapTrap"), hit_points(10), energy_points(10), attack_damage(0) 
{
	std::cout << name << " ClapTrap Created" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : name(n), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << name << " ClapTrap Created" <<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;	
}

ClapTrap &ClapTrap::operator= (const ClapTrap &other)
{
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << this->name << " ClapTrap Destroyed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << name << " attacks " << target << std::endl;
		energy_points -= 1;
	}
	else if (energy_points > 0 && hit_points <= 0)
		std::cout << name << " is dead :C" << std::endl;
	else if (energy_points <= 0)
		std::cout << name << " has no energy to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		std::cout << name << " takes " << amount << " damage" << std::endl;
		hit_points -= amount;
		if (hit_points <= 0)
			std::cout << name << " died" << std::endl;
	}
	else
		std::cout << name << " is ded" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << name << " reparing " << amount << " HP" << std::endl;
		hit_points += amount;
		energy_points -= 1;
	}
	else if (energy_points <= 0 && hit_points > 0)
		std::cout << name << " has no energy_points to perform this operation" << std::endl;
	else if (hit_points <= 0)
		std::cout << name << " is ded" << std::endl;
}