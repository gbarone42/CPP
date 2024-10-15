#include <iostream>
#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Example of adding multiple numbers
        int nums[] = {1, 5, 8, 12};
        sp.addNumbers(nums, sizeof(nums)/sizeof(nums[0]));

        std::cout << "Shortest span after adding more numbers: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span after adding more numbers: " << sp.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
