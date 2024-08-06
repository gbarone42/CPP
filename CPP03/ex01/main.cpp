#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
//Serena, My Love
int main()
{
    ClapTrap ct1("Clappy");
    ScavTrap st1("Scavvy");

    ct1.attack("target1");
    ct1.takeDamage(3);
    ct1.beRepaired(5);
    //ct1.guardGate();

    st1.attack("target2");
    st1.takeDamage(10);
    st1.beRepaired(1);
    st1.guardGate();

    return 0;
}


/*
In C++, when an object of a derived class is destroyed, the destructors are called in the reverse order of the constructors.
This ensures that any resources allocated by the derived class are cleaned up before the base class starts its destruction process
*/

//Last-In-First-Out (LIFO)

/*
is a method of organizing and manipulating data where
the most recently added item is the first one to be removed
*/