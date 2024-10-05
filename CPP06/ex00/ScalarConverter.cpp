#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>

// Static method to convert a string representation of a scalar value
void ScalarConverter::convert(const std::string& literal) {
    double value;
    bool isFloatLiteral = false;

    // Check if the literal ends with 'f', indicating a float literal
    if (literal[literal.size() - 1] == 'f' && literal != "inf" && literal != "-inf" && literal != "+inf") {  // Replaced literal.back() with literal[literal.size() - 1]
        std::string withoutF = literal.substr(0, literal.size() - 1);  // Remove 'f'
        value = std::strtod(withoutF.c_str(), 0);  // Replaced nullptr with 0
        isFloatLiteral = true;
    } else {
        value = std::strtod(literal.c_str(), 0);  // Replaced nullptr with 0
    }

    // If the input is invalid (contains non-numeric characters), print impossible for all
    if (literal.empty() || (!isFloatLiteral && *literal.c_str() != '0' && value == 0.0)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Handle special cases: nan and inf
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

    // Convert and print char
    std::cout << "char: ";
    char charResult = convertToChar(value);
    if (std::isprint(charResult)) {
        std::cout << "'" << charResult << "'" << std::endl;
    } else if (charResult >= 0 && static_cast<unsigned char>(charResult) < 128) {
        std::cout << "Non displayable" << std::endl;
    } else {
        std::cout << "impossible" << std::endl;
    }

    // Convert and print int
    std::cout << "int: ";
    int intResult = convertToInt(value);
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
    } else {
        std::cout << intResult << std::endl;
    }

    // Convert and print float
    std::cout << "float: " << std::fixed << std::setprecision(1) << convertToFloat(value) << (isFloatLiteral ? "f" : "f") << std::endl;

    // Convert and print double
    std::cout << "double: " << convertToDouble(value) << std::endl;
}

// Conversion functions
char ScalarConverter::convertToChar(double value) {
    if (value < 0 || value > 255 || std::isnan(value) || std::isinf(value)) {
        return -1;  // Indicating conversion is impossible
    }
    return static_cast<char>(static_cast<int>(value));
}

int ScalarConverter::convertToInt(double value) {
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value)) {
        return -1;  // Indicating conversion is impossible
    }
    return static_cast<int>(value);
}

float ScalarConverter::convertToFloat(double value) {
    return static_cast<float>(value);
}

double ScalarConverter::convertToDouble(double value) {
    return value;
}
