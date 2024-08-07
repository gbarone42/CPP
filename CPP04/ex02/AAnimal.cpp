#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
    std::cout << "Animal created." << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destroyed." << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "Animal sound! Sbrawawau" << std::endl;
}

std::string AAnimal::getType() const
{
    return type;
}
