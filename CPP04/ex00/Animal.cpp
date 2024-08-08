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
    std::cout << "Animals sound like SbrawawauWAUUU" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}
