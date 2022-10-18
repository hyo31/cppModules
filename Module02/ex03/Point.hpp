#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const float x, const float y);
        Point(Point const &copy);
        Point &operator=(Point const &copy);
        ~Point();

        Fixed getX() const;
        Fixed getY() const;
};

#endif
