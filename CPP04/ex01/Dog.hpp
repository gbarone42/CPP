#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain* brain;

public:
    Dog(); // Default Constructor
    Dog(const Dog& other); // Copy Constructor
    Dog& operator=(const Dog& other); // Copy Assignment Operator
    ~Dog(); // Destructor

    void makeSound() const; // Override function
    Brain* getBrain() const;
};

#endif // DOG_HPP
