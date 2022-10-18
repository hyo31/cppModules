#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "An animal is born!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "An animal is born!" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->type = copy.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal died." << std::endl;
}

std::string const &Animal::getType() const
{
	return (this->type);
}

void    Animal::makeSound() const
{
    std::cout << "Cant't make any sound :(" << std::endl;
}
