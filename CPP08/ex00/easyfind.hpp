#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>

template <typename T>
class EasyFind {
public:
    EasyFind(T* array, size_t size) : arr(array), arrSize(size) {}

    int find(int value) const
    {
        for (size_t i = 0; i < arrSize; ++i)
        {
            if (arr[i] == value) {
                return i; // Return index if found
            }
        }
        throw std::runtime_error("Value not found in the container.");
    }

private:
    T* arr;        // Pointer to the array
    size_t arrSize; // Size of the array
};

#endif // EASYFIND_HPP
