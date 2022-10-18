#include "Cat.hpp"

Cat::Cat():Animal()
{
    std::cout << "The animal is a cat." << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &copy):Animal(copy)
{
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    this->type = copy.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat died." << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

WrongCat::WrongCat():WrongAnimal()
{
    std::cout << "The wrong animal is a wrong cat." << std::endl;
    this->type = "Wrong cat";
}

WrongCat::WrongCat(const WrongCat &copy):WrongAnimal(copy)
{
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    this->type = copy.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong cat died." << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong meow" << std::endl;
}
