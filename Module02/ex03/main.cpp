#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    const Point a(0, 0);
	const Point b(50, 0);
	const Point c(25, 25);

    if (!bsp(a, b, c, Point(49, 1)))
        std::cout << "outside" << std::endl;
    else
        std::cout << "inside" << std::endl;
    return 0;
}
