#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits> // Include this header for numeric_limits

class Span {
public:
    Span(unsigned int n);
    void addNumber(int number);
    template <typename Iter>
    void addNumber(Iter begin, Iter end); // Improved addNumber function
    int shortestSpan();
    int longestSpan();

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};

#endif // SPAN_HPP
