#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat created." << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy created." << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat assigned." << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destroyed." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}
