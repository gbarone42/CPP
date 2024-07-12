#include "HumanB.h"

// Constructor with weapon initialized to 0 (null pointer in C++98)
HumanB::HumanB(const std::string& name) : name(name), weapon(0) {}

void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;  // Point to the existing weapon
}

void HumanB::attack() const {
    if (weapon) {  // Check if weapon is not a null pointer
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}
