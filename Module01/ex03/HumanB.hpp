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