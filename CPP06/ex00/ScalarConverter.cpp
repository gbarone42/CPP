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

void ScalarConverter::convert(const std::string& literal) {
    double value;
    bool isFloatLiteral = false;

    // Check if the literal ends with 'f', indicating a float literal
    if (literal.back() == 'f' && literal != "inf" && literal != "-inf" && literal != "+inf") {
        std::string withoutF = literal.substr(0, literal.size() - 1);  // Remove 'f'
        value = std::strtod(withoutF.c_str(), nullptr);
        isFloatLiteral = true;
    } else {
        value = std::strtod(literal.c_str(), nullptr);
    }

    // If the input is invalid (contains non-numeric characters), print impossible for all
    if (literal.empty() || (!isFloatLiteral && *literal.c_str() != '0' && value == 0.0)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Handle special cases
    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff" || literal == "inf" || literal == "inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // Convert and print
    std::cout << "char: ";
    char charResult = convertToChar(value);
    if (std::isprint(charResult)) {
        std::cout << "'" << charResult << "'" << std::endl;
    } else if (charResult >= 0 && static_cast<unsigned char>(charResult) < 128) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    std::cout << "int: ";
    int intResult = convertToInt(value);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << intResult << std::endl;
    }

    // For float and double, respect the isFloatLiteral flag to append the 'f' only for float literals
    if (isFloatLiteral) {
        std::cout << "float: " << std::fixed << std::setprecision(1) << convertToFloat(value) << "f" << std::endl;
    } else {
        std::cout << "float: " << std::fixed << std::setprecision(1) << convertToFloat(value) << "f" << std::endl;
    }

    std::cout << "double: " << convertToDouble(value) << std::endl;
}




//use of static_cast is required to explicitly convert values to the correct scalar types, except for promotion casts (e.g., from int to double).
//When converting from one scalar type to another in C++ (like double to int, or float to char), you are required to use static_cast to explicitly perform the conversion.
//This is important because narrowing conversions (conversions that reduce precision or range, like double to int) can result in loss of data (e.g., truncating decimal values). 
//Using static_cast forces the programmer to explicitly acknowledge and perform the conversion, ensuring that such conversions aren't done unintentionally or accidentally.
//A promotion cast occurs when you're converting from a smaller type to a larger type, where no precision or range is lost.
//A promotion happens when you convert a smaller type (like int) into a larger type (like double), which expands the value without losing precision.

//Narrowing Conversion (explicit): When converting from a larger type to a smaller type (e.g., double to int, float to char), use static_cast.
//Promotion (implicit): When converting from a smaller type to a larger type (e.g., int to double), you can rely on implicit casting.

//In C++, when you're promoting from a smaller type (e.g., int) to a larger type (e.g., double), the conversion is safe because the larger type can represent the full range of the smaller type without losing information.
// For this reason, you do not need to use static_cast for such conversions, and they can happen implicit
//Narrowing casts, such as converting from double to int, might result in loss of precision truncating decimal places or losing values outside the range of an int

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
