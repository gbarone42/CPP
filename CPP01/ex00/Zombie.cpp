#include "Zombie.h"
#include <iostream>

Zombie::Zombie(std::string n) : name(n) {}//: name(n) is an initializer list.

Zombie::~Zombie()
{
    std::cout << name << " is destroyed." << std::endl;
}

void Zombie::announce() const
{//member function named announce that does not modify any member variables
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


// destructors are special member functions