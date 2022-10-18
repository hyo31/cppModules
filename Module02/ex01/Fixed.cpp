#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = (value << Fixed::bits);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = (roundf(value * (1 << Fixed::bits)));
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

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
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

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}
