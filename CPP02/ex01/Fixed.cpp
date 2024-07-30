
// Fixed.cpp
#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}



//To convert an integer to fixed-point, multiply the integer by the scaling factor.
Fixed::Fixed(const int int_value) : fixed_point_value(int_value << fractional_bits)//initialize with integer value converting it in fixed point format
{//Each left shift doubles the number, so shifting it fractional_bits times effectively multiplies the integer by 2^fractional_bits
    std::cout << "Int constructor called" << std::endl;
}



//To convert a floating-point number to fixed-point, multiply the float by the scaling factor and round the result.
Fixed::Fixed(const float float_value) : fixed_point_value(roundf(float_value * (1 << fractional_bits))) //Initializes a Fixed object from a floating-point number by converting it into the class’s internal fixed-point format.
{
    std::cout << "Float constructor called" << std::endl;
}




Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixed_point_value = other.fixed_point_value;
    }
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_value = raw;
}






// To convert a fixed-point number back to floating-point, divide the fixed-point value by the scaling factor.
float Fixed::toFloat() const //Converts the internal fixed-point representation (fixed_point_value) into a floating-point number.
{
    return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}


// To convert a fixed-point number to an integer, perform a right bit-shift by the number of fractional bits.
int Fixed::toInt() const //Converts the internal fixed-point number to an integer by effectively discarding the fractional part.
{
    return fixed_point_value >> fractional_bits;//right bitwise shift
}







//overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}


//When the C++ compiler encounters this expression,
//it needs a way to handle the Fixed type on the right side of the << operator paired with an std::ostream (such as std::cout) on the left