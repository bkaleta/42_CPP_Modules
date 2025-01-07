/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:55 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:33:56 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &tref)	:	name(n), typeREF(tref)
{
}

HumanA::~HumanA()
{
}

void	HumanA::setName(std::string n)
{
	name = n;
}

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << typeREF.getType() << std::endl;
}