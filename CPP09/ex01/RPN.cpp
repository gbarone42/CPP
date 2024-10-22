#include "RPN.hpp"
#include <cstdlib>

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <climits> // for INT_MAX and INT_MIN

void RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::stack<int> numbers;
    std::string token;

    while (iss >> token)
    {
        // Check if the token is a number (including multi-digit numbers)
        if (token.find_first_not_of("0123456789") == std::string::npos)
        {
            numbers.push(atoi(token.c_str())); // Convert token to integer and push to stack
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (numbers.size() < 2)
            {
                throw std::runtime_error("Error: not enough operands.");
            }

            int right = numbers.top(); numbers.pop();
            int left = numbers.top(); numbers.pop();
            long long result; // Use long long to detect overflow

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

            numbers.push((int)result); // Push the valid result to the stack
        }
        else
        {
            throw std::runtime_error("Error: invalid token => " + token);
        }
    }

    // Check for errors related to the final state of the stack
    if (numbers.size() != 1)
    {
        throw std::runtime_error("Error: too many operands.");
    }

    // Print the final result
    std::cout << numbers.top() << std::endl;
}
