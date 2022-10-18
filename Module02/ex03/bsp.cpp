#include "Point.hpp"
#include <cmath>

float   det(Point const u, Point const v)
{
    float ad;
    float bc;

    ad = (u.getX().toFloat() * v.getY().toFloat());
    bc = (u.getY().toFloat() * v.getX().toFloat());
    return (ad - bc);
}

bool    bsp(Point const a, Point const b, Point const c, Point const point)
{
    float   x;
    float   y;
    float   test;

    x = ((det(point, c) - det(a, c)) / det(b, c));
    y = -((det(point, b) - det(a, b)) / det(b, c));
    test = a.getX().toFloat() + (x * b.getX().toFloat()) + (y * c.getX().toFloat());
    std::cout << test << std::endl;
    test = a.getY().toFloat() + (x * b.getY().toFloat()) + (y * c.getY().toFloat());
    std::cout << test << std::endl;
    std::cout << x << ", " << y << ", " << (x + y) << std::endl;    
    if (x > 0 && y > 0 && ((x + y) < 1))
        return true;
    return false;
}
