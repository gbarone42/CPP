#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>
#include <iostream>

//HumanA has a weapon as a reference, ensuring that it always possesses a weapon.class HumanA {
private:
    std::string name;
    Weapon& weapon;// Reference to Weapon, ensuring HumanA always has a weapon

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif
