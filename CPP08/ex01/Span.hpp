#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iostream>

class Span {
public:

    Span(unsigned int n);                 
    Span(const Span &other);   
    Span& operator=(const Span &other);
    ~Span();                               
    void addNumber(int number);          

    template <typename Iter>
    void addNumbers(Iter begin, Iter end); 

    int shortestSpan();         
    int longestSpan();          

private:
    std::vector<int> numbers;            
    unsigned int maxSize;                 
};

#endif // SPAN_HPP
