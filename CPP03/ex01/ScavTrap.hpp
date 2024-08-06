#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    ScavTrap(std::string name);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};

#endif // SCAVTRAP_HPP

//ScavTrap inherits the protected members name, hitPoints, energyPoints, and attackDamage from ClapTrap.
//The public methods attack, takeDamage, beRepaired, and getter functions are inherited and accessible in ScavTrap
//ScavTrap overrides the attack method to provide a specific implementation while still utilizing the inherited properties
//The ScavTrap constructor calls the ClapTrap constructor using : ClapTrap(name), ensuring proper initialization.
//Additional initializations specific to ScavTrap are then performed (e.g., setting different values for hitPoints, energyPoints, and attackDamage).
//When a ScavTrap object is destroyed, it first executes its own destructor.
//After completing the ScavTrap destructor, the base ClapTrap destructor is automatically called to clean up the base class part of the object.
//By inheriting from ClapTrap, the ScavTrap class gains access to and can leverage the properties and methods defined in ClapTrap, demonstrating the principles of inheritance in C++.