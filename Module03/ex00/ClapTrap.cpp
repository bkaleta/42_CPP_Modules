/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:19 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/26 22:16:26 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hit_points = 10;
	energy_points = 10;
	attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " created" << std::endl; 
} 
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " Destroyed" << std::endl;
}
void	ClapTrap::attack(const std::string &target)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << std::endl;
		energy_points--;
	}
	else if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead and canno't attack..." << std::endl;
	else
		std::cout << "ClapTrap " << name << " has no energy to attack" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " takes " << amount << " hit points" << std::endl;
		hit_points -= amount;
		if (hit_points <= 0)
			std::cout << "ClapTrap " << name << " died" << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points > 0 && hit_points > 0)
	{
		std::cout << "ClapTrap " << name << " is reparing " << amount << " hit points" << std::endl;
		hit_points += amount;
		energy_points--;
	}
	else if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " is dead therefore cannot repair" << std::endl;
	else
		std::cout << "ClapTrap " << name << " has not enough energy to repair" << std::endl;
}