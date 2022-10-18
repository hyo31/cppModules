#include "Fixed.hpp"

// default constructor
Fixed::Fixed()
{
	this->value = 0;
}

//
// fixed to int and float values
//
Fixed::Fixed(int const value)
{
    this->value = (value << Fixed::bits);
}

Fixed::Fixed(float const value)
{
    this->value = (roundf(value * (1 << Fixed::bits)));
}

// copy constructor
Fixed::Fixed(Fixed const &copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
}

// copy assigment operator overload
Fixed &Fixed::operator=(Fixed const &copy)
{
    this->value = copy.getRawBits();
    return (*this);
}

//
// overlaod of comparison operators
//
bool Fixed::operator>(Fixed const &copy) const
{
	return (this->getRawBits() > copy.getRawBits());
}

bool Fixed::operator<(Fixed const &copy) const
{
	return (this->getRawBits() < copy.getRawBits());
}

bool Fixed::operator>=(Fixed const &copy) const
{
	return (this->getRawBits() >= copy.getRawBits());
}

bool Fixed::operator<=(Fixed const &copy) const
{
	return (this->getRawBits() <= copy.getRawBits());
}

bool Fixed::operator==(Fixed const &copy) const
{
	return (this->getRawBits() == copy.getRawBits());
}

bool Fixed::operator!=(Fixed const &copy) const
{
	return (this->getRawBits() != copy.getRawBits());
}

//
// overload of arithmetic operators
//
Fixed Fixed::operator+(Fixed const &copy)
{
    this->setRawBits(this->getRawBits() + copy.getRawBits());
    return(*this);
}

Fixed Fixed::operator-(Fixed const &copy)
{
    this->setRawBits(this->getRawBits() - copy.getRawBits());
    return(*this);
}

Fixed Fixed::operator*(Fixed const &copy)
{
    this->setRawBits((this->getRawBits() * copy.getRawBits()) / (1 << Fixed::bits));
    return(*this);
}

Fixed Fixed::operator/(Fixed const &copy)
{
    this->setRawBits((this->getRawBits() * (1 << Fixed::bits))/ copy.getRawBits());
    return(*this);
}

//
// overload of increment and decrement operators
//
Fixed Fixed::operator++()
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	operator++();
	return (temp);
}

Fixed Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	operator--();
	return (temp);
}

// put the fixed number to output as a float
std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
    out << value.toFloat();
    return (out);
}

//
// functions for to get the min value
//
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    return (a);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (b);
    return (a);
}

Fixed const &min(Fixed const &a, Fixed const &b)
{
    return (Fixed::min(a, b));    
}

Fixed &min(Fixed &a, Fixed &b)
{
    return (Fixed::min(a, b));
}

//
// functions for to get the max value
//
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    return (b);
}

Fixed const &max(Fixed const &a, Fixed const &b)
{
    return (Fixed::max(a, b));    
}

Fixed &max(Fixed &a, Fixed &b)
{
    return (Fixed::max(a, b));
}

//
// set and get bits
//
int Fixed::getRawBits(void) const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

//
// convert fixed to float and int
//
float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return (this->value >> Fixed::bits);
}
