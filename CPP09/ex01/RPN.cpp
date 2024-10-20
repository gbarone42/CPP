#include "RPN.hpp"

void RPN::evaluate(const std::string& expression)
{
    std::istringstream iss(expression);
    std::stack<int> numbers;
    std::string token;

    while (iss >> token)
	{
        if (isdigit(token[0]))
		{
            numbers.push(std::stoi(token));
        } else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
            if (numbers.size() < 2)
			{
                throw std::runtime_error("Error: not enough operands.");
            }

            int right = numbers.top(); numbers.pop();
            int left = numbers.top(); numbers.pop();
            int result;

            if (token == "+")
			{
                result = left + right;
            }
			else if (token == "-")
			{
                result = left - right;
            }
			else if (token == "*")
			{
                result = left * right;
            }
			else
			{ // token == "/"
                if (right == 0)
				{
                    throw std::runtime_error("Error: division by zero.");
                }
                result = left / right;
            }
            numbers.push(result);
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
