#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span {
public:
    Span(unsigned int N);
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};

#endif // SPAN_HPP
