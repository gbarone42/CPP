#include "HumanB.h"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {} //constructor initialize humanB without a weapon at the beginning

void HumanB::setWeapon(Weapon& weapon) //allowing setting a weapon at any time
{
    this->weapon = &weapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << "No weapon to attack with!" << std::endl;
    }
}
