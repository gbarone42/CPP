#include <iostream>
#include <limits>
#include <vector>
#include "Span.hpp"

int main()
{
    Span sp = Span(10);


    std::vector<int> values(6);
    values[0] = -100;
    values[1] = 99;
    values[2] = 30;
    values[3] = 40;
    values[4] = 50;
    values[5] = 60;

    sp.addNumbers(values.begin(), values.end());

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    return 0;
}