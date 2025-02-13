/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:22 by bkaleta           #+#    #+#             */
/*   Updated: 2025/02/13 22:07:38 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class   ClapTrap
{
protected:
    std::string name;
    int         hit_points;
    int         energy_points;
    int         attack_damage;
public:
    // Default constructor
    ClapTrap(void);
    // constructor with name
    ClapTrap(std::string n);
    // Copy constructor
    ClapTrap(const ClapTrap &other);
    // Assign operator
    ClapTrap &operator = (const ClapTrap &other); 
    // Destructor
    ~ClapTrap();
    void    attack(const std::string &target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};

#endif