#include "Weapon.h"

Weapon::Weapon(const std::string& type) : type(type) {} //initialize the type of weapon

const std::string& Weapon::getType() const
{
    return type;//returns the type of weapon
}

void Weapon::setType(const std::string& type)
{
    this->type = type;
}
