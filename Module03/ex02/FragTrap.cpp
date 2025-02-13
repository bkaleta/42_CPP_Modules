/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 22:14:26 by bkaleta           #+#    #+#             */
/*   Updated: 2025/02/13 23:26:52 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	:	ClapTrap("Default FragTrap")
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << name << " FragTrap Created" << std::endl;
}

FragTrap::FragTrap(std::string name)
	:	ClapTrap("FragTrap")
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << name << " FragTrap Created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	:	ClapTrap(other)
{
	*this = other;
}

FragTrap &FragTrap::operator= (const FragTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator= (other);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << name << " FragTrap Destroyed" << std::endl;
}

void	FragTrap::highFiveGuys()
{
	std::cout << name << " HIGH FIVE ALL" << std::endl;
}