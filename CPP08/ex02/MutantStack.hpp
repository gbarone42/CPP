#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <stdexcept>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // Iterator type definition
    class iterator : public std::iterator<std::input_iterator_tag, T>
    {
        public:
            explicit iterator(typename std::deque<T>::iterator it) : current(it) {}

            T& operator*() { return *current; }
            iterator& operator++() { current--; return *this; } // Decrement to move backwards
            bool operator!=(const iterator& other) const { return current != other.current; }
        private:
            typename std::deque<T>::iterator current;
    };

    // Constructor and Destructor
    MutantStack() {}
    ~MutantStack() {}

    // Adding stack methods from std::stack
    using std::stack<T>::push;
    using std::stack<T>::pop;
    using std::stack<T>::top;
    using std::stack<T>::size;
    using std::stack<T>::empty;

    // Iterator methods
    iterator begin()
    {
        return iterator(this->c.end() - 1); // Start from the last element
    }
    
    iterator end()
    {
        return iterator(this->c.begin() - 1); // One before the first element
    }
};

#endif // MUTANTSTACK_HPP
