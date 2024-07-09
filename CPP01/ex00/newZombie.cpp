#include "Zombie.h"
//Zombie*: The return type of the function, indicating that it returns a pointer to a Zombie object.
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
//return new Zombie(name);: This line is where the Zombie object is created dynamically using the new operator.
//new Zombie(name): The new operator allocates memory on the heap for a new Zombie object and calls the Zombie constructor with name as the argument to initialize the object.
//The constructor of the Zombie class likely sets this name to a member variable inside the Zombie object.