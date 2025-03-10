/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:34:07 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:34:08 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : type("Unknown")
{
	// std::cout << "Weapon with default type: Unknown created" << std::endl;
}
Weapon::Weapon(const std::string &initWep) : type(initWep)
{
	// std::cout << "Weapon created with type: " << type << std::endl;
}
Weapon::~Weapon()
{
	// std::cout << "Weapon of type " << type << " destroyed" << std::endl;
}
const	std::string &Weapon::getType() const
{
	return type;
}
void	Weapon::setType(const std::string &newType)
{
	type = newType;
	// std::cout << "Weapon set to: " << type << std::endl;
}