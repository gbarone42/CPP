

#include <iostream>
#include "Array.hpp" // Include your Array class template definition



int main() 
{
    try
    {
        Array<int> intArray(5); // Create an array of 5 integers
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            intArray[i] = i * 10; // Initialize array elements
        }

        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Accessing out of bounds
        std::cout << intArray[0] << std::endl; 
        std::cout << intArray[1] << std::endl;
        std::cout << intArray[2] << std::endl;
        std::cout << intArray[3] << std::endl;
        std::cout << intArray[4] << std::endl;
        std::cout << intArray[0] << std::endl;//reading
        std::cout << intArray[5] << std::endl;//out of bound
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }


    Array<Point> pointArray(3);

     pointArray[0] = Point(1, 2);// writing
    pointArray[1] = Point(3, 4);
    pointArray[2] = Point(5, 6);

    
    std::cout << "Array of Points:" << std::endl;
    for (unsigned int i = 0; i < pointArray.size(); ++i)
    {
        pointArray[i].display();
    }

    return 0;
}


/*#include <iostream>
#include "Array.hpp"


int main()
{
    try
    {
        Array<int> intArray(5); // Create an array of 5 integers
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            intArray[i] = i * 10; // Initialize array elements
        }

        std::cout << "Array elements: ";
        for (unsigned int i = 0; i < intArray.size(); ++i)
        {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Accessing out of bounds
        std::cout << intArray[0] << std::endl; 
        std::cout << intArray[1] << std::endl;
        std::cout << intArray[2] << std::endl;
        std::cout << intArray[3] << std::endl;
        std::cout << intArray[4] << std::endl;
        std::cout << intArray[0] << std::endl;
        std::cout << intArray[5] << std::endl;//out of bound
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
*/