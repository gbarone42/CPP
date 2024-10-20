#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque> // For underlying container
#include <stdexcept> // For exceptions

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Typedef for the iterator type
    typedef typename std::deque<T>::iterator iterator;

    // Constructor and Destructor
    MutantStack() {}
    ~MutantStack() {}

    // Using the stack methods
    using std::stack<T>::push;
    using std::stack<T>::pop;
    using std::stack<T>::top;
    using std::stack<T>::size;
    using std::stack<T>::empty;

    // Iterator methods
    iterator begin() {
        return this->c.begin(); // Access the underlying container's begin
    }
    
    iterator end() {
        return this->c.end(); // Access the underlying container's end
    }
};

#endif // MUTANTSTACK_HPP
