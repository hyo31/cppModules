#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
}

void HumanB::setWeapon(Weapon &type)
{
    weapon = &type;
}

void HumanB::attack(void)
{
    if (weapon)
	    std::cout << _name << " attacks with his " << weapon->getType() << std::endl;
    else
        std::cout << "no weapon set for " << _name << std::endl;
}