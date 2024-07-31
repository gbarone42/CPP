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

    st1.attack("target2");
    st1.takeDamage(10);
    st1.beRepaired(1);
    st1.guardGate();

    return 0;
}
