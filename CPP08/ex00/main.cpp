#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    try
    {
        //vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found 3 in vector at position: " << std::distance(vec.begin(), it) << std::endl;

        //list
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);
        
        std::list<int>::iterator it2 = easyfind(lst, 20);
        std::cout << "Found 20 in list at position: " << std::distance(lst.begin(), it2) << std::endl;

        
        it = easyfind(vec, 6); // This will throw an exception
       // it2 = easyfind(lst, 80);
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    
        

    return 0;
}

//vec and lst are two different types of containers
//pushback methodd is used to add elements in each container
//"distance" is used to compute the position of the found value relative to the beginning of the vector