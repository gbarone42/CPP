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

    virtual void makeSound() const; // Virtual function with default implementation
    std::string getType() const;
};

#endif // ANIMAL_HPP

/*
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
//base class
class Animal {
protected:
    std::string type;

public:
    Animal();
    virtual ~Animal();
    virtual void makeSound() const;//virtual keyword in the base class to allow derived classes to override methods //virtual keyword tells the compiler to support dynamic dispatch, ensuring that the correct method is called based on the actual object type at runtime, , not the type of the pointer or reference used for the function call.
    std::string getType() const;
};

#endif // ANIMAL_HPP
*/