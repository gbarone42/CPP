#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:

/*
    // Canonical Orthodox Form
    RPN();                          // Default Constructor
    RPN(const RPN& other);           // Copy Constructor
    RPN& operator=(const RPN& other);// Copy Assignment Operator
    ~RPN();                         // Destructor

    // Member function
  */
    void evaluate(const std::string& expression);
};

#endif // RPN_HPP
