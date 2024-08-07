#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    {
        Dog basic;
        {
            Dog tmp = basic;  // Copy constructor is called here
            tmp = basic;  // Assignment operator is called here
        }  // tmp goes out of scope and is destroyed
    }  // basic goes out of scope and is destroyed

    std::cout << "\n--- Testing array of Animals ---\n" << std::endl;

    AAnimal* animals[4];

    for (int i = 0; i < 2; ++i) {
        animals[i] = new Dog();
    }

    for (int i = 2; i < 4; ++i) {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- Testing Wrong Animal Section ---\n" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound(); // should output the wrong cat sound
    wrongMeta->makeSound(); // should output the wrong animal sound

    delete wrongMeta;
    delete wrongCat;

    return 0;
}
