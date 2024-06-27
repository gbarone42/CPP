#include "Zombie.h"

void randomChump(std::string name) {
    Zombie tempZombie(name);
    tempZombie.announce();
}
