#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    if (N < 1)
        return NULL;
    Zombie  *new_horde = new Zombie[N];
    for (int i = 0; i < N; i++)
        new_horde[i].set_name(name);
    return (new_horde);
}
