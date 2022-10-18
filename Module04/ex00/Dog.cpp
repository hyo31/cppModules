#include "Dog.hpp"

Dog::Dog():Animal()
{
    std::cout << "The animal is a dog." << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &copy):Animal(copy)
{
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    this->type = copy.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog died." << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
