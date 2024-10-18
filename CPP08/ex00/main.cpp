#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"
#include <algorithm>//for find

int main()
{
    try
    {
        //vec
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::vector<int>::iterator it3 = vec.begin();

        std::cout << std::endl;
        std::cout << "Elements in vector: ";
         while (it3 != vec.end())
        {
            std::cout << *it3 << " "; // Dereferencing the iterator to access the value
            ++it3; // Move to the next element
        }
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Found 3 in vector at position: " << std::distance(vec.begin(), it) << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;

        //list
        std::list<int> list;
        list.push_back(10);
        list.push_back(20);
        list.push_back(30);
        list.push_back(40);
        list.push_back(50);
        
        //t
        std::list<int>::iterator it2 = easyfind(list, 20);
        std::list<int>::iterator it4 =list.begin();

        std::cout << std::endl;
        std::cout << "Elements in list: ";
         while (it4 != list.end())
        {
            std::cout << *it4 << " ";
            ++it4; // 
        }
        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "Found 20 in list at position: " << std::distance(list.begin(), it2) << std::endl;
        it2 = easyfind(list, 50);
        std::cout << "Found 50 in list at position: " << std::distance(list.begin(), it2) << std::endl;

        
        //
        it2 = easyfind(list, 80); // l'exception ok
        //it = easyfind(vec, 6); // l'exception ok
        //it2 = easyfind(list, 20);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    
        

    return 0;
}

//vec and lst

//An iterator is an object that allows you to traverse through the elements of a container without exposing the underlying implementation details of the container.