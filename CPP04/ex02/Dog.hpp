#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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
