/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:33:58 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:33:59 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"


class HumanA
{
private:
	std::string name;
	Weapon &typeREF;
public:
	HumanA(std::string n, Weapon &tref);
	~HumanA();
	void	setName(std::string n);
	void	attack();
};


#endif