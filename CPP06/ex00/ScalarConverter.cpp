#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>


void ScalarConverter::convert(const std::string& literal) //static member function of the ScalarConverter class
{
    double value; // it is neeeded to store the numeric value after converting the string 'literal' to a double
    bool isFloatLiteral = false;// a flag to indicate if the input string represent a float literal


    if (literal[literal.size() - 1] == 'f' && literal != "inf" && literal != "-inf" && literal != "+inf")
    {
        std::string withoutF = literal.substr(0, literal.size() - 1);  // the f gets removed
        value = std::strtod(withoutF.c_str(), 0);  //the string without the f is converted to a double
        isFloatLiteral = true;
    }
    else
    {
        value = std::strtod(literal.c_str(), 0);  // even if the string literal is not a float literal it converts the string literal to a double
    }

    if (literal.empty() || (!isFloatLiteral && *literal.c_str() != '0' && value == 0.0))//checks if it is empty //when isFloatLiteral is true the if statement will not trigger unless literal.empty() is true // This checks whether the first character of the string literal is not '0' //This checks if the value (the result of converting literal to double) is equal to 0.0.
    {//So when isFloatLiteral is true, the if statement will not trigger unless literal.empty() is true.
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Handle special cases: nan and inf
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

    // Convert and print char
    std::cout << "char: ";
    char charResult = convertToChar(value);
    if (std::isprint(charResult))//check if cherResult ASCII values between 32 and 126
    {
        std::cout << "'" << charResult << "'" << std::endl;// printed in ' ' 
    }
    else if (charResult >= 0 && static_cast<unsigned char>(charResult) < 128)//non displayable
    {
        std::cout << "Non displayable" << std::endl;
    }
    else
    {
        std::cout << "impossible" << std::endl;
    }

    // Convert and print int
    std::cout << "int: ";
    int intResult = convertToInt(value);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())//smallest and larger possible integer
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << intResult << std::endl;
    }

    // Convert and print float //"fixed-point" notation as opposed to "scientific" notation //
    std::cout << "float: " << std::fixed << std::setprecision(1) << convertToFloat(value) << (isFloatLiteral ? "f" : "f") << std::endl;

    // Convert and print double
    std::cout << "double: " << convertToDouble(value) << std::endl;
}

// Conversion functions
char ScalarConverter::convertToChar(double value)
{
    if (value < 0 || value > 255 || std::isnan(value) || std::isinf(value))
    {
        return -1;  // Indicating conversion is impossible
    }
    return static_cast<char>(static_cast<int>(value));
}

int ScalarConverter::convertToInt(double value)
{
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value))
    {
        return -1;  // Indicating conversion is impossible
    }
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
