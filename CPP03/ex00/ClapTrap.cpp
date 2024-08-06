#include "ClapTrap.hpp"


//constructor
ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) //set initial value
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}


//constructor test
/*
ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(0), energyPoints(0), attackDamage(1000) //set initial value
{
    std::cout << "ClapTrap " << name << " created." << std::endl;
}
*/

//destructor 
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

//attack method
void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)//check if claptrap has energy points and hit points to perform an attack. //ClapTrap can’t do anything if it has no hit points or energy points left. 
    {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;//decrease energy points after attacking
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
    }
}

//take damage method
void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= static_cast<unsigned int>(hitPoints))// // Set hit points to 0 if damage is greater than or equal to current hit points
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now at 0 hit points!" << std::endl;
    }
    else
    {
        hitPoints -= amount;// subtract damage from hit points
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and now has " << hitPoints << " hit points left!" << std::endl;
    }
}

//repair method
void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)// check if ClapTrap can be repaired
    {
        hitPoints += amount;//// Increase hit points by the repair amount
        std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
        energyPoints--;//// Decrease energy points after repair
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to be repaired!" << std::endl;//ClapTrap can’t do anything if it has no hit points or energy points left
    }
}



////getter methods

std::string ClapTrap::getName() const
{
    return name;
}

int ClapTrap::getHitPoints() const
{
    return hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
    return energyPoints;
}

int ClapTrap::getAttackDamage() const 
{
    return attackDamage;
}
