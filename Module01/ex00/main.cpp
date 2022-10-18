#include "Zombie.hpp"

int main(void)
{
    Zombie *new_zombie;

    randomChump("random chump");
    new_zombie = newZombie("new zombie");
    new_zombie->announce();
    delete new_zombie;
    return (0);
}