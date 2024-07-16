#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixed_point_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_value) : fixed_point_value(int_value << fractional_bits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float float_value) : fixed_point_value(roundf(float_value * (1 << fractional_bits))) {
    std::cout << "Float constructor called" << std::endl;
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
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
    fixed_point_value = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(fixed_point_value) / (1 << fractional_bits);
}

int Fixed::toInt() const {
    return fixed_point_value >> fractional_bits;
}

Fixed& Fixed::operator++() {
    fixed_point_value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    fixed_point_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.fixed_point_value != 0)
        return Fixed(this->toFloat() / other.toFloat());
    else
        throw std::runtime_error("Division by zero.");
}

bool Fixed::operator>(const Fixed& other) const {
    return this->fixed_point_value > other.fixed_point_value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->fixed_point_value < other.fixed_point_value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->fixed_point_value >= other.fixed_point_value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->fixed_point_value <= other.fixed_point_value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->fixed_point_value == other.fixed_point_value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->fixed_point_value != other.fixed_point_value;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
