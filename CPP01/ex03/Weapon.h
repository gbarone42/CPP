#ifndef WEAPON_H
#define WEAPON_H

#include <string>
//this class holds a single private member but provides public methods to access it
class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string& type);//// Constructor to initialize the weapon type
    const std::string& getType() const;// Getter for the weapon type
    void setType(const std::string& type);// Setter for the weapon type
};

#endif
