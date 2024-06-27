#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string name = "");  // Constructor with default parameter
    ~Zombie();                 // Destructor
    void announce() const;     // Announce method
    void setName(std::string name); // Setter for name
};

// Declare the zombieHorde function
Zombie* zombieHorde(int N, std::string name);

#endif
