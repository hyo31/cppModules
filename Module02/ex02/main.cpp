#include "Fixed.hpp"

int main()
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(Fixed(5.05f) * Fixed(2));
    Fixed const d(b);

    a = Fixed( 10.42f );

    std::cout << "\nvalues:" << std::endl;
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "\ncomparison:" << std::endl;
    std::cout << (b == d) << std::endl;
    std::cout << (c == d) << std::endl;
    std::cout << (b >= d) << std::endl;
    std::cout << (c <= d) << std::endl;
    std::cout << (b > d) << std::endl;
    std::cout << (c < d) << std::endl;
    
    std::cout << "\narithmetic:" << std::endl;
    std::cout << (a + d) << std::endl;
    std::cout << (a - d) << std::endl;
    std::cout << (a * 2) << std::endl;
    std::cout << (a / 2) << std::endl;
    std::cout << (a / 2) << std::endl;

    std::cout << "\nincrement and decrement:" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << c << std::endl;

    std::cout << "\nmin and max values:" << std::endl;
    std::cout << Fixed::min( a, c ) << std::endl;
    std::cout << Fixed::min( b, c ) << std::endl;
    std::cout << Fixed::max( a, c ) << std::endl;
    std::cout << Fixed::max( b, c ) << std::endl;

    return 0;
}
