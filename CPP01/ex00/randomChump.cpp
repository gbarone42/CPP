#include "Zombie.h"

void randomChump(std::string name)
{
    Zombie tempZombie(name);
    tempZombie.announce();
}


//The function randomChump creates a Zombie object on the stack rather than on the heap, which is why it does not require the use of new and delete. Understanding the differences between stack and heap memory allocations can clarify why new and delete are unnecessary in this scenario.