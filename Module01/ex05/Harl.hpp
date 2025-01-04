/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:05:02 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/04 13:35:12 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>
#include <map>

class Harl {
private:
    // Deklaracje funkcji członkowskich dla poziomów logowania
    void debug();
    void info();
    void warning();
    void error();

    // Typ wskaźnika na funkcję członkowską
    typedef void (Harl::*HarlMethod)();

    // Mapa do przechowywania poziomów logowania i wskaźników do metod
    std::map<std::string, HarlMethod> logLevels;

public:
    Harl();
	~Harl();
    void complain(const std::string& level);
};


#endif