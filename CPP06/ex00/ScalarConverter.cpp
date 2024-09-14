#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>

void ScalarConverter::convert(const std::string& literal)
{
    // Replace nullptr with 0 for C++98 compatibility
    double value = std::strtod(literal.c_str(), 0);

    // Handle special cases
    if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // Convert and print
    std::cout << "char: ";
    char charResult = convertToChar(value);
    if (std::isprint(charResult))
        std::cout << "'" << charResult << "'" << std::endl;
    else if (charResult >= 0 && static_cast<unsigned char>(charResult) < 128) // Fixed comparison
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    int intResult = convertToInt(value);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << intResult << std::endl;

    std::cout << "float: " << std::fixed << std::setprecision(1) << convertToFloat(value) << "f" << std::endl;
    std::cout << "double: " << convertToDouble(value) << std::endl;
}

char ScalarConverter::convertToChar(double value)
{
    return static_cast<char>(value);
}

int ScalarConverter::convertToInt(double value)
{
    return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(double value)
{
    return static_cast<float>(value);
}

double ScalarConverter::convertToDouble(double value)
{
    return value;
}
