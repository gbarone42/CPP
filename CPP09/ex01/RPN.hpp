#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:
    void evaluate(const std::string& expression);
};

#endif
