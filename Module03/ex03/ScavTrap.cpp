#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap()
{
    std::cout << "ScavTrap is called " << this->name << "!" << std::endl;
    this->hp = 100;
    this->ep = 50;
    this->_ep = 50;
    this->ap = 20;
}

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    this->name = name;
    std::cout << "ScavTrap is called " << this->name << "!" << std::endl;
    this->hp = 100;
    this->ep = 50;
    this->_ep = 50;
    this->ap = 20;
}

ScavTrap::ScavTrap(const ScavTrap &copy):ClapTrap(copy)
{
    *this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ap = copy.ap;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->name << " has died!" << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
    if (!this->hp)
        std::cout << "ScavTrap " << this->name << " has no HitPoints left and can not attack." << std::endl;
    else if (!this->ep)
        std::cout << "ScavTrap " << this->name << " has no EnergyPoints left and can not attack." << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->ap << " points of damage!" << std::endl;
        this->ep--;
    }
    return ;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap: " << this->name << " is now in Gate Keeper mode." << std::endl;
}
unsigned int ScavTrap::getEp()const
{
    return(this->_ep);
}
