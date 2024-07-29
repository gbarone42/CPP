// main.cpp
#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed a;// HERE THE DEFAULT CONSTRUCTOR
    Fixed b(a);// here the copy constructor is used
    Fixed c;// DEF
    c = b;// ASS

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}

