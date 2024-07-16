#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
private:
    std::string type;

public:
    Weapon(const std::string& type);//constructor
    const std::string& getType() const;//getter
    void setType(const std::string& type);//setter
};

#endif // WEAPON_H
