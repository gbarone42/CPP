#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;// without a virtual destructor only the animal destructor would be called, potentially leading to resource leaks in the Dog class.
    delete i;

    std::cout << "\n ---///--- Wrong Animal Section ---///--- \n" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); //
    wrongMeta->makeSound();

    delete wrongMeta;
    delete wrongCat;

    return 0;
}


//Polymorphism: This allows treating objects of different types (i.e., Animal, Dog, Cat) as objects of a common base type (Animal).
//The correct function implementation is determined at runtime, enabling flexible and reusable code.
//Polymorphism is a core concept in OOP that allows objects of different types to be treated as objects of a common base type.
//It enables the same operation to behave differently on different classes.