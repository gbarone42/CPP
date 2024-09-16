#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>


//INUTILE
/*

// Private constructor to prevent instantiation
ScalarConverter::ScalarConverter() {}

// Copy constructor (private and unimplemented to prevent copying)
ScalarConverter::ScalarConverter(const ScalarConverter&) {}

// Copy assignment operator (private and unimplemented to prevent assignment)
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

// Destructor (private and empty)
ScalarConverter::~ScalarConverter() {}

*/

//converting a string representation of a scalar value to different scalar types (char, int, float, double) etc etc

void ScalarConverter::convert(const std::string& literal)
{
    // 
    double value = std::strtod(literal.c_str(), 0);// strtod converte una stringa in un double //c_str converte l'oggetto literal in una stringa c-style

    // casi speciali
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
    if (std::isprint(charResult))//checkka che sia printabile
        std::cout << "'" << charResult << "'" << std::endl;
    else if (charResult >= 0 && static_cast<unsigned char>(charResult) < 128) // Fixed comparison
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    int intResult = convertToInt(value);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) //checkka che il numero non sia out of range
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
