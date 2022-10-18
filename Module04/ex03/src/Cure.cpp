#include "../inc/Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{

}

Cure::Cure(const Cure &src) : AMateria("cure")
{
    *this = src;
}

Cure &Cure::operator=(const Cure &src)
{
    this->_type = src._type;
    return (*this);
}

AMateria *Cure::clone() const
{
    Cure *clone = new Cure;
    return (clone);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* shoots an Cure bolt at "
        << target.getName() << " *" << std::endl;
}
