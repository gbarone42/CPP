#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal(); // Default Constructor
    WrongAnimal(const WrongAnimal& other); // Copy Constructor
    WrongAnimal& operator=(const WrongAnimal& other); // Copy Assignment Operator
    virtual ~WrongAnimal(); // Destructor

    void makeSound() const; // Regular virtual function
    std::string getType() const;
};

#endif // WRONGANIMAL_HPP
