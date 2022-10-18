#include "../inc/AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{

}

std::string const &AMateria::getType() const
{
    return(this->_type);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "* AMateria used on " << target.getName() << "*" << std::endl;
}
