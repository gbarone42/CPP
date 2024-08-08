#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* brain;

public:
    Cat(); // Default Constructor
    Cat(const Cat& other); // Copy Constructor
    Cat& operator=(const Cat& other); // Copy Assignment Operator
    ~Cat(); // Destructor

    void makeSound() const; // Override function
    Brain* getBrain() const;
};

#endif // CAT_HPP
