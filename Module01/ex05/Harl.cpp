/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:05:00 by bkaleta           #+#    #+#             */
/*   Updated: 2025/01/04 13:34:22 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Implementacja metod klasy Harl
Harl::Harl() 
{
    // Powiązanie poziomów logowania z metodami
    logLevels["DEBUG"] = &Harl::debug;
    logLevels["INFO"] = &Harl::info;
    logLevels["WARNING"] = &Harl::warning;
    logLevels["ERROR"] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::debug() 
{
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
}

void Harl::info() {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money.\n";
}

void Harl::warning() {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free.\n";
}

void Harl::error() {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(const std::string& level) {
    // Sprawdzenie, czy poziom logowania istnieje w mapie
    if (logLevels.find(level) != logLevels.end()) {
        // Wywołanie odpowiedniej metody za pomocą wskaźnika
        (this->*logLevels[level])();
    } else {
        std::cout << "[UNKNOWN] Invalid log level: " << level << "\n";
    }
}