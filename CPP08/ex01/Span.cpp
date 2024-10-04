#include "Span.hpp"

// Constructor
Span::Span(unsigned int N) : maxSize(N) {}

// Add a number to the Span
void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::overflow_error("Cannot add more numbers: Span is full.");
    }
    numbers.push_back(number);
}

// Calculate the shortest span
int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers stored to find a span.");
    }

    std::vector<int> temp = numbers;
    std::sort(temp.begin(), temp.end());
    int minSpan = INT_MAX;

    for (size_t i = 0; i < temp.size() - 1; ++i) {
        int span = temp[i + 1] - temp[i];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

// Calculate the longest span
int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers stored to find a span.");
    }

    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}
