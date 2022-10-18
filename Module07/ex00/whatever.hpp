# ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
using namespace std;

template <typename T> T t_min(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T> T t_max(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T> void t_swap(T &x, T &y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

#endif
