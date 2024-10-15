#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>

class Span {
public:
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(int number);
    void addNumbers(int* numbers, size_t size); // New function to add multiple numbers
    int shortestSpan() const;
    int longestSpan() const;

private:
    int* numbers;           // Dynamic array to store numbers
    unsigned int maxSize;   // Maximum size of the Span
    unsigned int currentSize; // Current size of the Span

    void copy(const Span &other); // Helper function for deep copy
};

#endif // SPAN_HPP
