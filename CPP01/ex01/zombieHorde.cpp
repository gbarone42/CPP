#include "Zombie.h"
#include <sstream> // Include the stringstream header

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];//allocation for N Zombie objects
    for (int i = 0; i < N; ++i)
    {
        std::stringstream ss;
        ss << name << " #" << (i + 1); // << operator to append data
        horde[i].setName(ss.str()); // convert the stringstream to a string and set it
    }
    return horde;
}