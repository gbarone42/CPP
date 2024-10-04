#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> intArray(5); // Create an array of 5 integers
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 10; // Initialize array elements
        }

        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Accessing out of bounds
        std::cout << intArray[10] << std::endl; // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
