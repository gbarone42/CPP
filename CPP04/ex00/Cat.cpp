#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
