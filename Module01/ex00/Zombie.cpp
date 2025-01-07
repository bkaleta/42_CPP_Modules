/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:28 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:33:29 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << zombie_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	zombie_name = "";
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << zombie_name << " died!" << std::endl;
}

void Zombie::set_name(std::string name)
{
	zombie_name = name;
}