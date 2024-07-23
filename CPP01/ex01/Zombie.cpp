#include "Zombie.h"
#include <iostream>


// Default constructor
Zombie::Zombie() : name("") {}// Initialization list sets the name to an empty string
Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string n)
{
    name = n;
}
