# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
using namespace std;

template <typename T> void iter(T *array, size_t length, void (*func)(T))
{
    for (int i = 0; i < length; i++)
    {
        func(array[i]);
    }
}

#endif
