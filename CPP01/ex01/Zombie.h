#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
private:
    std::string name;

public:
    // Default constructor
    Zombie();    

    // Constructor with default parameter
    Zombie(std::string name);  

    // Destructor
    ~Zombie();                 

    // Method to announce the zombie
    void announce() const;     

    // Setter for the name
    void setName(std::string name); 
};

// Declare the zombieHorde function
// helper method
Zombie* zombieHorde(int N, std::string name);

#endif
