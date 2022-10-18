#include "../inc/MateriaSource.hpp"
#include "../inc/Ice.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    ICharacter* henk = new Character("henk");
    ICharacter* kees = new Character("kees");
    AMateria* tmp;
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    tmp = src->createMateria("ice");
    me->equip(tmp);
    me->use(0, *henk);
    me->use(1, *henk);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    me->use(0, *kees);
    me->use(1, *kees);

    //me->unequip(0);
    //me->use(0, *henk);
    //me->use(1, *henk);
//
    //me->unequip(1);
    //me->use(0, *bob);
    //me->use(1, *bob);
    
    delete bob;
    delete henk;
    delete kees;
    delete me;
    delete src;
    return 0;
}
