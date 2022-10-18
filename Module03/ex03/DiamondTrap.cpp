#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("Nobody_clap_name")
{
    this->name = "Nobody";
    std::cout << "DiamondTrap is called " << this->name << "!" << std::endl;
    this->hp = 100;
    this->ep = getEp();
    this->ap = 30;
}

DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name")
{
    this->name = name;
    std::cout << "DiamondTrap is called " << this->name << "!" << std::endl;
    this->hp = 100;
    this->ep = getEp();
    this->ap = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    this->name = copy.name + "_clap_name";
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ap = copy.ap;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    //std::cout << this->hp << this->ep << this->ap << std::endl;
    std::cout << "DiamondTrap " << this->name << " has died!" << std::endl;
}

void    DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap: My name is " << this->name << std::endl;
    std::cout << "ClapTrap: My name is " << ClapTrap::name << std::endl;
}
