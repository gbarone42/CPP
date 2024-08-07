#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
    type = "Dog";
    std::cout << "Dog created." << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Dog copy created." << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog assigned." << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destroyed." << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof!" << std::endl;
}
