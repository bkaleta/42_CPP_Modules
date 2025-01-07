/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:31 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:33:32 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string zombie_name;
public:
	Zombie();
	~Zombie();
	void	set_name(std::string name);
	void	announce();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif