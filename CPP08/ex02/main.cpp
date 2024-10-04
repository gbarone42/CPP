#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; // Outputs 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Outputs 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it; // Move iterator to second element
    --it; // Move back to first element

    while (it != ite) {
        std::cout << *it << std::endl; // Outputs all elements
        ++it;
    }

    std::stack<int> s(mstack); // Copy to a standard stack
    return 0;
}
