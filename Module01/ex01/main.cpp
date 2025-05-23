/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:38 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:33:39 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *horde;
	int		N = 10, i = 0;

	horde = zombieHorde(N, "Legion");
	if (horde)
	{
		while (i < N)
		{
			horde[i].announce();
			i++;
		}
		delete [] horde;
	}
	return (0);
}