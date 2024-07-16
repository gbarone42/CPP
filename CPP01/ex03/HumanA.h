#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>
#include <iostream>
//humanA always has a weapon
class HumanA {
private:
    std::string name;
    Weapon& weapon;//reference to a weapon

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif // HUMANA_H
