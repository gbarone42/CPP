#include "Zombie.h"
#include <sstream> // Include the stringstream header

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];//allocates space for N Zombie objects.
    for (int i = 0; i < N; ++i)
    {
        std::stringstream ss; // Create a stringstream object
        ss << name << " #" << (i + 1); // Use the stream insertion operator to append data
        horde[i].setName(ss.str()); // Convert the stringstream to a string and set it
    }
    return horde;
}