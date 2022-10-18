#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap()
{
    std::cout << "FragTrap is called " << this->name << "!" << std::endl;
    this->hp = 100;
    this->ep = 100;
    this->ap = 30;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
    this->name = name;
    std::cout << "FragTrap is called " << this->name << "!" << std::endl;
    this->hp = 100;
    this->ep = 100;
    this->ap = 30;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    *this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    this->name = copy.name;
    this->hp = copy.hp;
    this->ep = copy.ep;
    this->ap = copy.ap;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " has died!" << std::endl;
}

void    FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: " << this->name << " requests High Fives!!!" << std::endl;
}
