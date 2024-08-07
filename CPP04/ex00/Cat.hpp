#ifndef CAT_HPP
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
