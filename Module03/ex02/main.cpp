/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:24 by bkaleta           #+#    #+#             */
/*   Updated: 2025/02/13 23:27:26 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "__________________________________" << std::endl << std::endl;

    FragTrap defaultFragTrap;
    FragTrap firstFragTrap("First");
    defaultFragTrap.attack("Proper");
    firstFragTrap.highFiveGuys();

    return 0;
}