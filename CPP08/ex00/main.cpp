#include <iostream>
#include "easyfind.hpp"

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    
    EasyFind<int> finder(arr, size);

    try
    {
        int index = finder.find(3);
        std::cout << "Found value at index: " << index << std::endl;
    } catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        int index = finder.find(6);
        std::cout << "Found value at index: " << index << std::endl;
    } catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
