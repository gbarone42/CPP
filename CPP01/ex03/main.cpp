#include "Weapon.h"
#include "HumanA.h"
#include "HumanB.h"

int main()
{
    Weapon club("crude spiked club");
    
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    
    HumanB jim("Jim");
    jim.attack();  // Jim has no weapon initially
    jim.setWeapon(club);
    jim.attack();
    
    return 0;
}
