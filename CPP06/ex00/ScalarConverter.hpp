#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();  // Private constructor to prevent instantiation

    static char convertToChar(double value);
    static int convertToInt(double value);
    static float convertToFloat(double value);
    static double convertToDouble(double value);
};

#endif
