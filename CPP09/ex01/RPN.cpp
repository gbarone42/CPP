#include "RPN.hpp"
#include <cstdlib>

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <climits> 

void RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::stack<int> numbers;
    std::string token;

    while (iss >> token)
    {
        if (token.find_first_not_of("0123456789") == std::string::npos)
        {
            numbers.push(atoi(token.c_str()));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (numbers.size() < 2)
            {
                throw std::runtime_error("Error: not enough operands.");
            }

            int right = numbers.top(); numbers.pop();
            int left = numbers.top(); numbers.pop();
            long long result; //detect overflow

            if (token == "+")
            {
                result = (long long)left + (long long)right;
                if (result > INT_MAX || result < INT_MIN) throw std::overflow_error("Error: overflow during addition.");
            }
            else if (token == "-")
            {
                result = (long long)left - (long long)right;
                if (result > INT_MAX || result < INT_MIN) throw std::overflow_error("Error: overflow during subtraction.");
            }
            else if (token == "*")
            {
                result = (long long)left * (long long)right;
                if (result > INT_MAX || result < INT_MIN) throw std::overflow_error("Error: overflow during multiplication.");
            }
            else
            { // token == "/"
                if (right == 0)
                {
                    throw std::runtime_error("Error: division by zero.");
                }
                result = left / right;
            }

            numbers.push((int)result);
        }
        else
        {
            throw std::runtime_error("Error: invalid token => " + token);
        }
    }
    if (numbers.size() != 1)
    {
        throw std::runtime_error("Error: too many operands.");
    }

    std::cout << numbers.top() << std::endl;
}

/*
The std::stack provides a simple interface with the essential operations: push(), pop(), and top().
These operations allow us to easily manage the operands as they come in from the RPN expression and perform operations with minimal complexity.
*/

/*

// Default Constructor
RPN::RPN() {
}

// Copy Constructor
RPN::RPN(const RPN& other) {
}

// Copy Assignment Operator
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
    }
    return *this;
}

// Destructor
RPN::~RPN() {

}


*/