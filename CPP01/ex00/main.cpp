#include "Zombie.h"

int main()
{
    // Demonstrate dynamic allocation (heap)
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;  // Cleaning up
    // Demonstrate automatic allocation (stack)
    randomChump("StackZombie");
    return 0;
}
//creating a Zombie class along with functions to manage instances of this class 
//both dynamically (using the heap)
//and automatically (using the stack).