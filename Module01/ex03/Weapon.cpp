#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_name)
{
	type = weapon_name;
}

const std::string &Weapon::getType(void)
{
	return (type);
}

void Weapon::setType(const std::string &weaponName)
{
	type = weaponName;
}
