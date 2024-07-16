// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int fixed_point_value;
    static const int fractional_bits = 8;

public:
    Fixed(); // Default constructor
    Fixed(const int int_value); // Constructor from integer
    Fixed(const float float_value); // Constructor from floating-point
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const; // Convert to float
    int toInt() const; // Convert to integer

    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
};

#endif // FIXED_HPP
