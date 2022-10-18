#include "../inc/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice::Ice(const Ice &src) : AMateria("cure")
{
    *this = src;
}

Ice &Ice::operator=(const Ice &src)
{
    this->_type = src._type;
    return (*this);
}

AMateria *Ice::clone() const
{
    Ice *clone = new Ice;
    return (clone);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at "
        << target.getName() << " *" << std::endl;
}
