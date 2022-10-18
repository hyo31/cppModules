#include "whatever.hpp"

int main()
{
    int     a = 1;
    int     b = 0;
    char    A = 'a';
    char    B = 'b';

    cout << t_min(a, b) << endl;
    cout << t_max(a, b) << endl;
    t_swap(a, b);
    std::cout << a << ", " << b << std::endl;

    cout << t_min(A, B) << endl;
    cout << t_max(A, B) << endl;
    t_swap(A, B);
    std::cout << A << ", " << B << std::endl;
    return (0);
}
