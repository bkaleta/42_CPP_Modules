/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:45 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:33:46 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *newHorde;
	int		i;
	if (N <= 0)
		return (nullptr);
	i = 0;
	newHorde = new Zombie[N];
	while (i < N)
	{
		newHorde[i].set_name(name);
		i++;
	}
	return (newHorde);
}