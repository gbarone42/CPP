#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon* weapon;

public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif
