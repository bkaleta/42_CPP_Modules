/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:24 by bkaleta           #+#    #+#             */
/*   Updated: 2025/02/13 22:07:29 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap trap("Trap");
    ClapTrap claptrap("ClapTrap");
    ClapTrap klon("klon");
    ClapTrap defaultTrap;
    
    trap.attack("ClapTrap");
    claptrap.takeDamage(5);
    claptrap.beRepaired(2);
    claptrap.attack("Trap");
    trap.takeDamage(10);
    klon = trap;
    klon.attack("ClapTrap");
    klon.beRepaired(2);
    
    std::cout << "__________________________________" << std::endl;
    
    ScavTrap defaultScavTrap;
    ScavTrap properScavTrap("Proper");
    defaultScavTrap.attack("Proper");
    properScavTrap.guardGate();

    return 0;
}