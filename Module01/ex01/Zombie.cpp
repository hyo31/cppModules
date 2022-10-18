#include "Zombie.hpp"

Zombie::Zombie(std::string name) : newName(name){}
Zombie::Zombie(){}

void    Zombie::announce(void)
{
    std::cout << newName << ": BraiiiiiiinnnzzzZ" << std::endl;
}

void    Zombie::set_name(std::string name)
{
    newName = name;
}

Zombie::~Zombie()
{
    std::cout << newName << " is destroyed" << std::endl;
}
