#include "HumanA.h"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {} //constructor receives and stores a reference to a weapon

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
