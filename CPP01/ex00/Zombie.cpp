#include "Zombie.h"
#include <iostream>
//constructo definition
//Zombie::Zombie(std::string n) defines the constructor for the Zombie class. This constructor takes a single argument n of type std::string, which represents the name of the zombie.
Zombie::Zombie(std::string n) : name(n) {}//: name(n) is an initializer list. It initializes the name member variable of the Zombie class with the value provided in n. Initializer lists are more efficient than assigning values in the body of the constructor because they directly initialize the members before the body of the constructor is executed.

Zombie::~Zombie()
{//Zombie::~Zombie() defines the destructor for the Zombie class. Destructors are special member functions which are called when an object of the class is destroyed (i.e., when it goes out of scope or is explicitly deleted).
    std::cout << name << " is destroyed." << std::endl;//Inside the destructor, std::cout << name << " is destroyed." << std::endl; prints a message to the console indicating that this particular zombie has been destroyed. This is useful for debugging purposes, to understand when objects are being cleaned up. std::endl not only moves to the next line but also flushes the output stream
}

void Zombie::announce() const
{//void Zombie::announce() const defines a member function named announce that does not modify any member variables (as indicated by the const qualifier at the end of the method signature). This function allows a Zombie object to perform an action, which is to announce itself.
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
