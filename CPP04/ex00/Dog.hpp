#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(); // Default Constructor
    Dog(const Dog& other); // Copy Constructor
    Dog& operator=(const Dog& other); // Copy Assignment Operator
    ~Dog(); // Destructor

    void makeSound() const; // Override function
};

#endif // DOG_HPP

/*
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
*/