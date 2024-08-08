#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
    Cat(); // Default Constructor
    Cat(const Cat& other); // Copy Constructor
    Cat& operator=(const Cat& other); // Copy Assignment Operator
    ~Cat(); // Destructor

    void makeSound() const; // Override function
};

#endif // CAT_HPP


/*#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

//derived class
class Cat : public Animal {
public:
    Cat();
    ~Cat();
    void makeSound() const;
};

#endif // CAT_HPP
*/