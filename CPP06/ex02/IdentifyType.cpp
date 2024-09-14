#include "IdentifyType.hpp"
#include <cstdlib>
#include <iostream>

// Randomly generates an instance of A, B, or C and returns it as a Base pointer
Base* generate(void) {
    srand(static_cast<unsigned int>(time(0)));
    int random = rand() % 3;

    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return 0; // Replaced nullptr with 0 for C++98 compatibility
    }
}

// Identifies the type of the object pointed to by Base* p
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identifies the type of the object referred to by Base& p
void identify(Base& p) {
    // Use dynamic_cast to test the type and check if it returns non-null
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}