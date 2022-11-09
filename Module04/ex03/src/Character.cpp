#include "../inc/Character.hpp"

Character::Character() : _name("without a name")
{
    for(int i = 0; i < 4; i++)
        this->inv[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
    for(int i = 0; i < 4; i++)
        this->inv[i] = NULL;
}

Character::~Character()
{
    for(int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete(this->inv[i]);
    }
}

Character::Character(const Character &src) : _name(src.getName())
{
    for(int i = 0; i < 4; i++)
        this->inv[i] = src.inv[i]->clone();
}

Character &Character::operator=(const Character &src)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete this->inv[i];
        this->inv[i]= src.inv[i]->clone();
    }
    return (*this);
}

std::string const &Character::getName() const
{
    return(this->_name);
}

void    Character::equip(AMateria *m)
{
    if(!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (!this->inv[i])
        {
            this->inv[i] = m;
            return ;
        }
    }
}

void    Character::unequip(int idx)
{
    if (this->inv[idx])
        this->inv[idx] = NULL;
}

void    Character::use(int idx, ICharacter &target)
{
    if (this->inv[idx])
        this->inv[idx]->use(target);
    else
        std::cout << "nothing at this index." << std::endl;
}
