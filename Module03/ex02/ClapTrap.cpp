#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "Nobody";
    std::cout << "ClapTrap is called " << this->name << "!" << std::endl;
    this->hp = 10;
    this->ep = 10;
    this->ap = 0;
}

ClapTrap::ClapTrap(std::string const name)
{
    this->name = name;
    std::cout << "ClapTrap is called " << this->name << "!" << std::endl;
    this->hp = 10;
    this->ep = 10;
    this->ap = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ap = copy.ap;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " has died!" << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (!this->hp)
        std::cout << "ClapTrap " << this->name << " has no HitPoints left and can not attack." << std::endl;
    else if (!this->ep)
        std::cout << "ClapTrap " << this->name << " has no EnergyPoints left and can not attack." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->ap << " points of damage!" << std::endl;
        this->ep--;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (!this->hp)
        std::cout << this->name << " has no HitPoints left and can not take more damage." << std::endl;
    else
    {
        this->hp = this->hp - amount;
        std::cout << this->name << " took " << amount << " damage and has " << this->hp << " HealthPoints left!" << std::endl;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->hp)
        std::cout << this->name << " has no HitPoints left and can not repair." << std::endl;
    else if (!this->ep)
        std::cout << this->name << " has no EnergyPoints left and can not repair." << std::endl;
    else
    {
        this->hp = this->hp + amount;
        std::cout << this->name << " repaired itself and now has " << this->hp << " HealthPoints!" << std::endl;
    }
    return ;
}
