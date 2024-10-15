#include "Span.hpp"
#include <limits>

// Constructor
Span::Span(unsigned int N) : maxSize(N), currentSize(0) {
    numbers = new int[N]; // Allocate memory for the array
}

// Destructor
Span::~Span() {
    delete[] numbers; // Deallocate memory
}

// Copy constructor
Span::Span(const Span &other) {
    copy(other);
}

// Assignment operator
Span &Span::operator=(const Span &other) {
    if (this != &other) {
        delete[] numbers; // Free existing memory
        copy(other);      // Copy new data
    }
    return *this;
}

// Helper function for deep copy
void Span::copy(const Span &other) {
    maxSize = other.maxSize;
    currentSize = other.currentSize;
    numbers = new int[maxSize];
    for (unsigned int i = 0; i < currentSize; ++i) {
        numbers[i] = other.numbers[i];
    }
}

// Add a single number to the Span
void Span::addNumber(int number) {
    if (currentSize >= maxSize) {
        throw std::overflow_error("Cannot add more numbers: Span is full.");
    }
    numbers[currentSize++] = number; // Add the number and increment the size
}

// Add multiple numbers to the Span
void Span::addNumbers(int* nums, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        addNumber(nums[i]); // Use addNumber to add each number
    }
}

// Calculate the shortest span
int Span::shortestSpan() const {
    if (currentSize < 2) {
        throw std::logic_error("Not enough numbers stored to find a span.");
    }

    int minSpan = std::numeric_limits<int>::max();

    for (unsigned int i = 0; i < currentSize; ++i) {
        for (unsigned int j = i + 1; j < currentSize; ++j) {
            int span = (numbers[i] > numbers[j]) ? (numbers[i] - numbers[j]) : (numbers[j] - numbers[i]); // Calculate span
            if (span < minSpan) {
                minSpan = span; // Update minSpan if a smaller span is found
            }
        }
    }
    return minSpan;
}

// Calculate the longest span
int Span::longestSpan() const {
    if (currentSize < 2) {
        throw std::logic_error("Not enough numbers stored to find a span.");
    }

    int min = numbers[0];
    int max = numbers[0];

    for (unsigned int i = 1; i < currentSize; ++i) {
        if (numbers[i] < min) {
            min = numbers[i]; // Find minimum
        }
        if (numbers[i] > max) {
            max = numbers[i]; // Find maximum
        }
    }
    return max - min; // Return the longest span
}
