#include "Span.hpp"


Span::Span(unsigned int n) : maxSize(n) {}


Span::Span(const Span &other) : numbers(other.numbers), maxSize(other.maxSize) {}


Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= maxSize)
    {
        throw std::out_of_range("Cannot add more numbers");
    }
    numbers.push_back(number);
}

// Explicit instantiation of the template method
template void Span::addNumbers<std::vector<int>::iterator>(std::vector<int>::iterator, std::vector<int>::iterator);


template <typename Iter>
void Span::addNumbers(Iter begin, Iter end)
{
    for (Iter it = begin; it != end; ++it)
    {
        addNumber(*it); //
    }
}


int Span::shortestSpan()
{
    if (numbers.size() < 2)
    {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::vector<int> sortedNumbers(numbers); 
    std::sort(sortedNumbers.begin(), sortedNumbers.end()); 
    int shortest = std::numeric_limits<int>::max();

    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        shortest = std::min(shortest, sortedNumbers[i] - sortedNumbers[i - 1]);
    }

    return shortest;
}

//ongest span
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

