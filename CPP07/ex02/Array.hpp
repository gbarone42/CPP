#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template <typename T>//T is  placeholder for a datatype that will be specified later
class Array {
private:
    T* _array;
    unsigned int _size;

public:
//default
    Array() : _array(NULL), _size(0) {}

//costruttore con i parametri
    Array(unsigned int n) : _size(n)
    {
        _array = new T[n](); // default init
    }
//copia
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
            delete[] _array; // libera
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
//
class Point
{
public:
    Point(int x = 0, int y = 0) : _x(x), _y(y) {} //

    void display() const
    {
        std::cout << "Point(" << _x << ", " << _y << ")" << std::endl;
    }

private:
    int _x; //
    int _y; //
};

#endif // ARRAY_HPP

/*

#include <iostream>

class Point
{
public:
    // Default constructor
    Point(int x = 0, int y = 0) : _x(x), _y(y) {}

    // Copy constructor
    Point(const Point& other) : _x(other._x), _y(other._y) {}

    // Copy assignment operator
    Point& operator=(const Point& other)
    {
        if (this != &other)
        {
            _x = other._x;
            _y = other._y;
        }
        return *this;
    }

    // Destructor
    ~Point() {}

    // Display function
    void display() const
    {
        std::cout << "Point(" << _x << ", " << _y << ")" << std::endl;
    }

private:
    int _x; // X-coordinate
    int _y; // Y-coordinate
};


*/