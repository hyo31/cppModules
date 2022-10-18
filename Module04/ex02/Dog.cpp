#include "Dog.hpp"

Dog::Dog():Animal()
{
    std::cout << "The animal is a dog." << std::endl;
    this->type = "Dog";
    this->Brain = new class Brain();
}

Dog::Dog(const Dog &copy):Animal(copy)
{
    std::cout << "The animal is a dog." << std::endl;
    this->Brain = new class Brain;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    this->type = copy.type;
    *this->Brain = *copy.Brain;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog died." << std::endl;
    delete this->Brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

void    Dog::setIdea(int i, std::string newIdea)
{
    this->Brain->setIdea(i, newIdea);
}

std::string Dog::getIdea(int i) const
{
    return(this->Brain->getIdea(i));
}
