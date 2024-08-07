#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal created." << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destroyed." << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound! Sbrawawau" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
