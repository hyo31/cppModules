#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//member functions of Traps:
//  attack(string);
//  beRepaired(unsigned int);
//  takeDamage(unsigned int);
//  
//member fucntion of Scav:
//  guardGate();
//
//member fucntion of Frag:
//  highFivesGuys();
//

int main()
{
    ClapTrap a("Kees");
    ClapTrap b;
    ClapTrap c("Henk");
    ScavTrap d("Jaap");
    FragTrap e("Klaas");

    a.attack("Henk");
    a.beRepaired(10);
    a.takeDamage(20);
    a.attack("Henk");
    for(int i = 0; i < 11; i++)
        c.attack("Kees");
    b.beRepaired(100);
    d.attack("Henk");
    e.attack("Jaap");
    d.guardGate();
    e.highFivesGuys();
    return (0);
}
