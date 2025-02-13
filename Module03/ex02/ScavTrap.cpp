/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:59:09 by bkaleta           #+#    #+#             */
/*   Updated: 2025/02/13 23:27:26 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(void) 
	: ClapTrap("Default ScavTrap")
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
    std::cout << name << " ScavTrap Created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
	: ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << name << " ScavTrap Created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
}

ScavTrap &ScavTrap::operator= (const ScavTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " Destroyed" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << name << " SCAVTRAP ATTACKS " << target << ", dealing " << attack_damage << " damage!" << std::endl;
		energy_points -= 1;
	}
	else if (hit_points <= 0)
		std::cout << name << " is dead and cannot attack!" << std::endl;
	else
		std::cout << name << " has no energy to attack!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode!" << std::endl;
}