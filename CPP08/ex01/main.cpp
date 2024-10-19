#include <iostream>
#include <limits>
#include <vector>
#include "Span.hpp"

int main()
{
    Span sp = Span(10);

    // Initialize the vector with a specified size and then assign values
    std::vector<int> values(6); // Create a vector with 8 elements
    values[0] = -100;
    values[1] = 99;
    values[2] = 30;
    values[3] = 40;
    values[4] = 50;
    values[5] = 60;

    // Adding multiple numbers using addNumbers
    sp.addNumbers(values.begin(), values.end());

    // Calculate and print spans
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    return 0;
}