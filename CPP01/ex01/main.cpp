#include "Zombie.h"
#include <iostream>

int main()
{
    int N = 10; // Number of zombies
    std::string baseName = "Zombie";

    Zombie* horde = zombieHorde(N, baseName);

    for (int i = 0; i < N; ++i)
    {
        horde[i].announce();
    }

    delete [] horde; // Cleaning up allocated memory

    return 0;
}
