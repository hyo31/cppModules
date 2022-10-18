#include "DiamondTrap.hpp"

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
//member function of Diamond:
//  whoAmI();
//

int main()
{
    //ClapTrap a("Kees");
    //ClapTrap b;
    //ClapTrap c("Henk");
    //ScavTrap d("Jaap");
    //FragTrap e("Klaas");
    DiamondTrap f("Joop");

    //a.attack("Henk");
    //a.beRepaired(10);
    //a.takeDamage(20);
    //a.attack("Henk");
    //for(int i = 0; i < 11; i++)
    //    c.attack("Kees");
    //b.beRepaired(100);
    //d.attack("Henk");
    //e.attack("Jaap");
    //d.guardGate();
    //e.highFivesGuys();
    f.attack("Klaas");
    f.whoAmI();
    return (0);
}
