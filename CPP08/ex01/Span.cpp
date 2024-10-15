#include "Span.hpp"
#include <limits> // Include this header for numeric_limits

// Constructor
Span::Span(unsigned int n) : maxSize(n) {}

// Method to add a single number
void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
    {
        throw std::out_of_range("Cannot add more numbers");
    }
    numbers.push_back(number);
}

// Improved method to add multiple numbers
template <typename Iter>
void Span::addNumber(Iter begin, Iter end)
{
    for (Iter it = begin; it != end; ++it)
    {
        addNumber(*it); // Use the existing addNumber for validation
    }
}

// Method to find the shortest span
int Span::shortestSpan()
{
    if (numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers; // Copy to sort
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int shortest = std::numeric_limits<int>::max();
    
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < shortest)
        {
            shortest = span;
        }
    }
    return shortest;
}

// Method to find the longest span
int Span::longestSpan()
{
    if (numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return max - min;
}
