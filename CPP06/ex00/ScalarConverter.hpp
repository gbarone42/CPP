#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter();  // Private constructor to prevent instantiation

   
   /*
    //non serve a un caz    // Orthodox Canonical Form methods - private to prevent copying/instantiating
    ScalarConverter(const ScalarConverter&);            // Copy Constructor
    ScalarConverter& operator=(const ScalarConverter&); // Copy Assignment Operator
    ~ScalarConverter();                                 // Destructor
    */

   //declared and implemented as static methods
    static char convertToChar(double value);
    static int convertToInt(double value);
    static float convertToFloat(double value);
    static double convertToDouble(double value);
};

#endif
