#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed const &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->value = copy.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
    std::cout << "Assignment operator called" << std::endl;
    this->value = copy.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}
