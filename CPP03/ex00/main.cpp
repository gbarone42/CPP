#include "ClapTrap.hpp"
//Aaaaand... OPEN!
int main()
{
    ClapTrap ct1("Clappy");

    ct1.attack("target1");
    ct1.takeDamage(3);
    ct1.beRepaired(5);
    ct1.attack("target2");
    ct1.takeDamage(20000);//kill
    ct1.beRepaired(1);

    return 0;
}
