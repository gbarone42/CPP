#include "HumanB.h"

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {} // //indicating that it does not point to any object initially

void HumanB::setWeapon(Weapon& weapon) //allowing setting a weapon at any time
{
    this->weapon = &weapon;
}

void HumanB::attack() const
{
    if (weapon)
    {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    else
    {
        std::cout << "No weapon to attack with!" << std::endl;
    }
}
