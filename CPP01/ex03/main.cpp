#include "Weapon.h"
#include "HumanA.h"
#include "HumanB.h"

int main()
{
    Weapon Rifle("AK 47");
    
    HumanA bob("Bob", Rifle);
    bob.attack();
    Rifle.setType("Akimbo Pistols");
    bob.attack();
    
    HumanB jim("Jim");
    jim.attack(); // Jim has no weapon initially
    jim.setWeapon(Rifle);
    jim.attack();
    
    return 0;
}
