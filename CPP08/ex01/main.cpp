#include <iostream>
#include "Span.hpp"

int main()
{
    Span sp = Span(8);
    sp.addNumber(9);
    sp.addNumber(9);
    sp.addNumber(-9);
    sp.addNumber(9);
    sp.addNumber(9);
    
    std::cout << sp.shortestSpan() << std::endl; // Expected output: 2 (3 and 6)
    std::cout << sp.longestSpan() << std::endl;  // Expected output: 14 (3 and 17)
    
    return 0;
}
