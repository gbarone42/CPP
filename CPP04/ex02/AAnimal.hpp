#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal(); // Default Constructor
    AAnimal(const AAnimal& other); // Copy Constructor
    AAnimal& operator=(const AAnimal& other); // Copy Assignment Operator
    virtual ~AAnimal(); // Destructor

    virtual void makeSound() const = 0; // Pure virtual function
    std::string getType() const;
};

#endif // AANIMAL_HPP
