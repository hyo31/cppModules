#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "An animal is born!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
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

WrongAnimal::WrongAnimal()
{
    std::cout << "A wrong animal is born!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    this->type = copy.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong animal died." << std::endl;
}

std::string const &WrongAnimal::getType() const
{
	return (this->type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "Cant't make any sound :(" << std::endl;
}
