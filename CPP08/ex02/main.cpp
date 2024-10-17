#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;
    
    // Basic stack operations
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top element: " << mstack.top() << std::endl; // Expected: 17
    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl; // Expected: 1

    // Push additional elements
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Using iterators to traverse the stack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << "Stack elements using iterator:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl; // Print each element
        ++it;
    }

    // Copying to std::stack to demonstrate interoperability
    std::stack<int> s(mstack);
    std::cout << "Top of std::stack: " << s.top() << std::endl; // Expected: 0

    // Additional tests
    mstack.push(42);
    std::cout << "Stack size after adding 42: " << mstack.size() << std::endl; // Expected: 5

    return 0;
}
