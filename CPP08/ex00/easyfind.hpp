#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>//for find
#include <stdexcept>// for runtime_error

template <typename T>
typename T::iterator easyfind(T& container, int value)//temeplate
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
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