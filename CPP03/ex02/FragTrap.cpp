#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " created." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << name << " destroyed." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        std::cout << "FragTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }
    else
    {
        std::cout << "FragTrap " << name << " has no energy or hit points left to attack!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}
