#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

//class template is a blueprint for a class that can work with any datatype

template <typename T>//T is  placeholder for a datatype that will be specified later
class Array {
private:
    T* _array;
    unsigned int _size;

public:
    Array() : _array(NULL), _size(0) {}

    Array(unsigned int n) : _size(n)
    {
        _array = new T[n](); // Default initialize elements
    }

    Array(const Array& other)
    {
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; ++i)
        {
            _array[i] = other._array[i];
        }
    }

    Array& operator=(const Array& other)
    {
        if (this != &other)
        {
            delete[] _array; // Free existing resource
            _size = other._size;
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
            {
                _array[i] = other._array[i];
            }
        }
        return *this;
    }

    ~Array()
    {
        delete[] _array;
    }

    T& operator[](unsigned int index) 
    {
        if (index >= _size)
        {
            throw std::out_of_range("Index out of bounds");
        }
        return _array[index];
    }

    unsigned int size() const
    {
        return _size;
    }
};

#endif // ARRAY_HPP


//
//
//A class template is a blueprint for creating classes that can operate with any data type. It allows you to define a class
//in a generic way so that it can handle different types without needing to create separate classes for each type. 