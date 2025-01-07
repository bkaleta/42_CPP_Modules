/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 00:34:02 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/08 00:34:03 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;    // Imię człowieka
    Weapon *wepPTR;      // Wskaźnik na broń (może być nullptr)

public:
    HumanB(std::string n);    // Konstruktor
    ~HumanB();                // Destruktor
    void setWeapon(Weapon &wptr);  // Setter dla broni
    void attack() const;           // Funkcja ataku
};

#endif