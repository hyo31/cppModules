#include "Zombie.hpp"

void    Zombie::announce(void)
{
    std::cout << new_name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::Zombie(std::string name)
{
    new_name = name;
}

Zombie::~Zombie()
{
    std::cout << new_name << " is destroyed" << std::endl;
}
