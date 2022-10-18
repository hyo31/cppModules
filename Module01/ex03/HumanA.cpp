#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type): type(type)
{
	_name = name;
}

void HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << type.getType() << std::endl;
}
