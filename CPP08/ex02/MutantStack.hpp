#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Constructor to allow construction with initial capacity
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {} // Copy constructor
    MutantStack &operator=(const MutantStack &other) { // Assignment operator
        if (this != &other) {
            std::stack<T>::operator=(other);
        }
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    iterator begin() {
        return this->c.begin(); // Access the underlying container's begin
    }

    iterator end() {
        return this->c.end(); // Access the underlying container's end
    }

    const_iterator begin() const {
        return this->c.begin(); // Const version for begin
    }

    const_iterator end() const {
        return this->c.end(); // Const version for end
    }
};

#endif // MUTANTSTACK_HPP
