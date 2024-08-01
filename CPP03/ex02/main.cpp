#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap ct1("Clappy");
    ScavTrap st1("Scavvy");
    FragTrap ft1("Fraggy");

    ct1.attack("target1");
    ct1.takeDamage(3);
    ct1.beRepaired(5);

    st1.attack("target2");
    st1.takeDamage(10);
    st1.beRepaired(1);
    st1.guardGate();

    ft1.attack("target3");
    ft1.takeDamage(20);
    ft1.beRepaired(10);
    ft1.highFivesGuys();

    return 0;
}
