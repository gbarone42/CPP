#include "Zombie.h"
#include <iostream>

int main()
{
    int N = 42; //zombies
    std::string baseName = "Zombie";

    Zombie* horde = zombieHorde(N, baseName);

    for (int i = 0; i < N; ++i)
    {
        horde[i].announce();
    }

    delete [] horde; // Cleaning up allocated memory

    return 0;
}

/*
// involves creating and managing multiple instances of a class—often referred to as a "horde" of objects.
// This exercise is a practical implementation of dynamic memory allocation and array handling in C++. 

// generate multiple Zombie objects at once,
// initializing each with the same name and storing them in a dynamically allocated array
int main()
{
    int N = 42; // Number of zombies
    std::string baseName = "Zombie";

    Zombie* horde = zombieHorde(N, baseName);

    for (int i = 0; i < N; ++i)
    {
        horde[i].announce();
    }

    delete [] horde; // Cleaning up allocated memory

    return 0;
}


//LIFO Order (Last In, First Out): In C++, objects stored in a dynamically allocated array are destroyed in reverse order of their creation when the array is deleted.
//This is because the destructor for the array needs to ensure that each object's destructor is called, starting from the last element to prevent potential issues like dependency-related errors or memory corruption.
*/

