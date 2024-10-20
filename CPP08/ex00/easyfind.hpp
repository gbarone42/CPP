#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>//find
#include <stdexcept>//runtime_error
#include <iostream>
#include <vector>
#include <list>
//attraverso
template <typename T>
typename T::iterator easyfind(T& container, int value)//temeplate cosi' funziona sia con list che con vector
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);//trova nel range dato da begin fino a end
    if (it == container.end())
    {
        throw std::runtime_error("Value not found");
    }
    return it;
}

#endif // EASYFIND_HPP

//"T& container" a reference to the container in which we find the value
//"find" returns an iterator pointing pointing to that value
//if it fails it return .end and an error message is printed
//STL = standard template library