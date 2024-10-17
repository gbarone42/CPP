#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span {
public:
    Span(unsigned int n) : maxSize(n) {}
    
    void addNumber(int number)
    {
        if (numbers.size() >= maxSize)
        {
            throw std::out_of_range("Cannot add more numbers");
        }
        numbers.push_back(number);
    }
    
    template <typename Iter>
    void addNumbers(Iter begin, Iter end)
    {
        for (Iter it = begin; it != end; ++it)
        {
            addNumber(*it); // Use the existing addNumber for validation
        }
    }
    
    int shortestSpan()
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
    
    int longestSpan()
    {
        if (numbers.size() < 2)
        {
            throw std::logic_error("Not enough numbers to find a span");
        }
        
        int min = *std::min_element(numbers.begin(), numbers.end());
        int max = *std::max_element(numbers.begin(), numbers.end());
        return max - min;
    }

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};
