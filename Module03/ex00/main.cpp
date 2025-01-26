/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:24 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/26 22:16:59 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap first("FIRST");
	ClapTrap second("SECOND");
	
	first.attack("SECOND");
	second.takeDamage(5);
	second.beRepaired(2);
	second.attack("FIRST");
	first.takeDamage(10);
	first.attack("SECOND");

	return (0);
}