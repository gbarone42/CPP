#include "Zombie.h"
//Zombie*: The return type of the function, indicating that it returns a pointer to a Zombie object.

//Dynamically creates a zombie and returns a pointer to it. This function showcases how to properly allocate and deallocate memory using new and delete.
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
//return new Zombie(name);: This line is where the Zombie object is created dynamically using the new operator.
//new Zombie(name): The new operator allocates memory on the heap for a new Zombie object and calls the Zombie constructor with name as the argument to initialize the object.
//The constructor of the Zombie class likely sets this name to a member variable inside the Zombie object.

//dynamic allocation needs to be manually freed