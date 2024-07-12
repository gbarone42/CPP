#include "Zombie.h"
// create a simple Zombie class with functions for dynamically and automatically creating Zombie instances
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


//automatic and dynamic memory memory management really have difference implications in the object lifecycle


// DYNAMIC : 
//The created Zombie object remains alive until delete is called on the returned pointer.
//This allows the object to outlive the scope of the function it was created in, making it accessible from other parts of the program as long as there is a pointer referencing it.

// AUTOMATIC
// Does not return a pointer or the object