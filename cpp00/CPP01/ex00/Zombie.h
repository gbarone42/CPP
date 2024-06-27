#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name);  // Constructor
    ~Zombie();                 // Destructor
    void announce() const;     // Announce method
};

// Function declarations
Zombie* newZombie(std::string name);   // Creates a new zombie on the heap
void randomChump(std::string name);    // Creates a zombie on the stack and makes it announce

#endif
