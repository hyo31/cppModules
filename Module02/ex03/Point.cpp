#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x2, const float y2) : x(x2), y(y2)
{
}

Point::Point(Point const &copy) : x(copy.x), y(copy.y)
{
    *this = copy;
}

Point::~Point()
{
}

Point &Point::operator=(Point const &copy)
{
    (Fixed)this->x = (Fixed)copy.x;
    (Fixed)this->y = (Fixed)copy.y;
    return (*this);
}

Fixed Point::getX() const
{
    return(this->x);
}

Fixed Point::getY() const
{
    return(this->y);
}
