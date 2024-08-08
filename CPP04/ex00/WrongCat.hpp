#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>
class WrongCat : public WrongAnimal {
public:
    WrongCat(); // Default Constructor
    WrongCat(const WrongCat& other); // Copy Constructor
    WrongCat& operator=(const WrongCat& other); // Copy Assignment Operator
    ~WrongCat(); // Destructor

    void makeSound() const;
};

#endif // WRONGCAT_HPP
