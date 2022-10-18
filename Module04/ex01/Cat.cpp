#include "Cat.hpp"

Cat::Cat():Animal()
{
    std::cout << "The animal is a cat." << std::endl;
    this->type = "Cat";
    this->Brain = new class Brain;
}

Cat::Cat(const Cat &copy):Animal(copy)
{
    std::cout << "The animal is a cat." << std::endl;
    this->Brain = new class Brain;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    *this->Brain = *copy.Brain;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat died." << std::endl;
    delete this->Brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

void    Cat::setIdea(int i, std::string newIdea)
{
    this->Brain->setIdea(i, newIdea);
}

std::string Cat::getIdea(int i) const
{
    return(this->Brain->getIdea(i));
}
