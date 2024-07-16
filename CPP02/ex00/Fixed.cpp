
// Fixed.cpp
#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixed_point_value = other.fixed_point_value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_value = raw;
}

