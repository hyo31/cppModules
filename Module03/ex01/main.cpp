#include "ScavTrap.hpp"

//member functions of ClapTrap & ScavTrap:
//attack(string);
//beRepaired(unsigned int);
//takeDamage(unsigned int);

int main()
{
    ClapTrap a("Kees");
    ClapTrap b;
    ClapTrap c("Henk");
    ScavTrap d("Jaap");

    a.attack("Henk");
    a.beRepaired(10);
    a.takeDamage(20);
    a.attack("Henk");
    for(int i = 0; i < 11; i++)
        c.attack("Kees");
    b.beRepaired(100);
    d.attack("Henk");
    return (0);
}
