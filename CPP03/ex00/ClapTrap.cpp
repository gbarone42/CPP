#include "ClapTrap.hpp"
//,,
ClapTrap::ClapTrap(std::string name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << name << " created." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)//ClapTrap can’t do anything if it has no hit points or energy points left.
    {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= static_cast<unsigned int>(hitPoints))
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and is now at 0 hit points!" << std::endl;
    }
    else
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount << " points of damage and now has " << hitPoints << " hit points left!" << std::endl;
    }
}


void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        hitPoints += amount;
        std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or hit points left to be repaired!" << std::endl;
    }
}



///getter methods


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
