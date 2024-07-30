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


// The number of fractional bits in a fixed-point representation affects the trade-off between precision and range.
// High Precision, Low Range : This is common in applications where precise fractional values are important.
// Low Precision, High Range : This is common in applications like large-scale financial calculations or scientific simulations.