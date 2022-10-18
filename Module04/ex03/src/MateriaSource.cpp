#include "../inc/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < 4; i++)
        this->inv[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete(this->inv[i]);
    }
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    for(int i = 0; i < 4; i++)
        this->inv[i] = src.inv[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->inv[i])
            delete this->inv[i];
        this->inv[i]= src.inv[i]->clone();
    }
    return (*this);
}

void    MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inv[i] && this->inv[i]->getType() == type)
            return(this->inv[i]->clone());
    }
    return 0;
}
