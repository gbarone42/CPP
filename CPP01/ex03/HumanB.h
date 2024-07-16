#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.h"
#include <string>
#include <iostream>
//humanB can optionally have a weapon and it can be set at any time
class HumanB {
private:
    std::string name;
    Weapon* weapon;//pointer to a weapon,

public:
    HumanB(const std::string& name);
    void setWeapon(Weapon& weapon);
    void attack() const;
};

#endif // HUMANB_H
