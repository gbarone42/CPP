#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.h"
#include <string>
#include <iostream>

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon);
    void attack() const;
};

#endif // HUMANA_H
