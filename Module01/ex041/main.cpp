/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:03:43 by bkaleta           #+#    #+#             */
/*   Updated: 2025/03/07 12:16:57 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myReplace.hpp"

int	main(int ac, char **av)
{
	myReplace	Sed;
	
	Sed.valid_input(ac);
	Sed.setter(av[1], av[2], av[3]);
	Sed.my_replace();
	
	return (0);
}