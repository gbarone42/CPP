#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
    std::string name;// passed to the constructor as a paramenter
    int hitPoints;//represents the health //
    int energyPoints;// attacking and repairing cost one energyPoint each //If energyPoints are 0, the ClapTrap cannot attack or repair itself, even if it has hit points remaining.
    int attackDamage; // This represents the amount of damage the ClapTrap can inflict on a target during an attack // This value determines how effective the ClapTrap is in combat situations

public:
    ClapTrap(std::string name);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Getter functions for testing purposes
    std::string getName() const;
    int getHitPoints() const;
    int getEnergyPoints() const;
    int getAttackDamage() const;
};

#endif // CLAPTRAP_HPP
