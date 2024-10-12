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
        std::string withoutF = literal.substr(0, literal.size() - 1);  // the f gets removed / 0 è l'indice di partenza , il secondo parametro è la lunghezza della sottostringa che vuoi estrarre
        value = std::strtod(withoutF.c_str(), 0);  //the string without the f is converted to a double
        isFloatLiteral = true;
    }
    else
    {
        value = std::strtod(literal.c_str(), 0);  // even if the string literal is not a float literal it converts the string literal to a double
    }

    if (literal.empty() || (!isFloatLiteral && *literal.c_str() != '0' && value == 0.0))//checks if it is empty //when isFloatLiteral is true the if statement will not trigger unless literal.empty() is true // This checks whether the first character of the string literal is not '0'
    {//Soooo when isFloatLiteral is true, the if statement will not trigger unless literal.empty() is truee
        std::cout << "char: impossible!" << std::endl;
        std::cout << "int: impossible!" << std::endl;
        std::cout << "float: impossible!" << std::endl;
        std::cout << "double: impossible!" << std::endl;
        return;
    }

    // nan and inf
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

    // 
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

    // ""fixed-point" notation" not ""scientific" notation" //
    std::cout << "float: " << std::fixed << std::setprecision(6) << convertToFloat(value) << "f" << std::endl;

    // Convert and print double
    std::cout << "double: " << convertToDouble(value) << std::endl;
}

// Conversion functions ----->


char ScalarConverter::convertToChar(double value)
{
    if (value < 0 || value > 255 || std::isnan(value) || std::isinf(value))
    {
        return -1;  //coneversione impossibilitata
    }
    return static_cast<char>(static_cast<int>(value));
}

int ScalarConverter::convertToInt(double value)
{//-2147483648
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() || std::isnan(value) || std::isinf(value))
    {
        return -1;  //impossible
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


/*
#include "ScalarConverter.hpp"

// Copy Constructor (private to prevent copying)
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    //copying
}

// Copy Assignment Operator (private to prevent copying)
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    // Check for self-assignment
    if (this != &other)
    {
        //ScalarConverter has no members.
    }
    return *this;
}

// Destructor (private to prevent instantiation and ensure static use)
ScalarConverter::~ScalarConverter()
{
    // but there's nothing to clean up.
}
*/