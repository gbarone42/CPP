#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal(); // Default Constructor
    Animal(const Animal& other); // Copy Constructor
    Animal& operator=(const Animal& other); // Copy Assignment Operator
    virtual ~Animal(); // Destructor

    virtual void makeSound() const; // Virtual function
    std::string getType() const;
};

#endif // ANIMAL_HPP
