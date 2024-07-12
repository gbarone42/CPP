#include "Weapon.h"

Weapon::Weapon(const std::string& type) : type(type) {}

const std::string& Weapon::getType() const {
    return type;
}//getType: This method provides read-only access to the type field, ensuring it cannot modify the Weapon object, hence the const qualifier at the end of the method signature.

void Weapon::setType(const std::string& type) {
    this->type = type; //Allows the type of the weapon to be changed after the weapon has been constructed.
}
