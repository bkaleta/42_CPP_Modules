/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:46:24 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/27 19:35:32 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap first("FIRST");
	ClapTrap second("SECOND");
	ClapTrap c("nazwa");
	
	first.attack("SECOND");
	second.takeDamage(5);
	second.beRepaired(2);
	second.attack("FIRST");
	first.takeDamage(10);
	c = first;
	c.attack("SECOND");
	first.attack("SECOND");

	return (0);
}