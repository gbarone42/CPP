// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int fixed_point_value;//stores the fixed point number
    static const int fractional_bits = 8;//static means it is shared across all instances.

public:
    Fixed(); // Default constructor
    Fixed(const Fixed& other); // Copy constructor
    Fixed& operator=(const Fixed& other); // Copy assignment operator
    ~Fixed(); // Destructor

    int getRawBits() const;
    void setRawBits(int const raw);
};

#endif // FIXED_HPP
