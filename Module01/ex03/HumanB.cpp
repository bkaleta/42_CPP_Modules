#include "HumanB.hpp"

// Konstruktor
HumanB::HumanB(std::string n) : name(n), wepPTR(nullptr) {
}

// Destruktor
HumanB::~HumanB() {
}

// Setter dla broni
void HumanB::setWeapon(Weapon &wptr) {
    wepPTR = &wptr;  // Przypisz adres obiektu Weapon
}

// Funkcja attack()
void HumanB::attack() const {
    if (wepPTR) { // Sprawdź, czy wskaźnik nie jest nullptr
        std::cout << name << " attacks with their " << wepPTR->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}