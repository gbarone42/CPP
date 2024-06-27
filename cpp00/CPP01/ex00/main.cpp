#include "Zombie.h"

int main() {
    // Demonstrate dynamic allocation (heap)
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;  // Cleaning up

    // Demonstrate automatic allocation (stack)
    randomChump("StackZombie");

    return 0;
}
