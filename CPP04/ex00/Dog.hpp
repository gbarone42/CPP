#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
////derived class
class Dog : public Animal {
public:
    Dog();
    ~Dog();
    void makeSound() const;
};

#endif // DOG_HPP
