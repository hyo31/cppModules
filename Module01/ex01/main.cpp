#include "Zombie.hpp"

int main(void)
{
    Zombie *new_horde;
    int     num = 10;

    new_horde = zombieHorde(num, "zombie");
    for (int i = 0; i < num; i++)
        new_horde[i].announce();
    delete[] new_horde;
    return (0);
}