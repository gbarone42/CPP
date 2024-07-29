#include "Fixed.hpp"
#include <cmath>


//default
Fixed::Fixed() : fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}


//int constructor
Fixed::Fixed(const int int_value) : fixed_point_value(int_value << fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

//float constructor
Fixed::Fixed(const float float_value) : fixed_point_value(roundf(float_value * (1 << fractional_bits))) {
    std::cout << "Float constructor called" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->fixed_point_value = other.fixed_point_value;
    }
    return *this;
}

//destructor
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

//getter
int Fixed::getRawBits() const {
    return fixed_point_value;
}

//getter
void Fixed::setRawBits(int const raw) {
    fixed_point_value = raw;
}

//Converts the fixed-point number to a floating-point number
float Fixed::toFloat() const {
    return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

//Converts the fixed-point number to an integer 
int Fixed::toInt() const {
    return fixed_point_value >> fractional_bits;
}

//prefix++
Fixed& Fixed::operator++() {
    fixed_point_value++;
    return *this;//returns a reference
}//this is used in expressions that use the new value of 'x'

//postfix++
Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;//This is a copy of the original object before it was incremented.
}//this is useful when you need the value of 'x' before it gets incremented

//prefix
Fixed& Fixed::operator--() {
    fixed_point_value--;
    return *this;
}

//postfix
Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    if (other.fixed_point_value != 0)
        return Fixed(this->toFloat() / other.toFloat());//converts both in float//Constructs a new Fixed object from the division result, converting the floating-point quotient back to fixed-point.
    else
        throw std::runtime_error("Division by zero.");// if the value of other is '0' then there is the risk of a runtime error
}



//6 comparison operator overloads for the Fixed class
//Determines if the Fixed object on the left of the > operator has a greater fixed_point_value than the Fixed object on the right.
//Each operator is overloaded to compare the fixed_point_value of two Fixed objects
bool Fixed::operator>(const Fixed& other) const
{
    return this->fixed_point_value > other.fixed_point_value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return this->fixed_point_value < other.fixed_point_value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return this->fixed_point_value >= other.fixed_point_value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return this->fixed_point_value <= other.fixed_point_value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return this->fixed_point_value == other.fixed_point_value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return this->fixed_point_value != other.fixed_point_value;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b) ? a : b;
}
