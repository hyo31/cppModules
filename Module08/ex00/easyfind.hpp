#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <ostream>

class NotFound : public std::exception
{
    public:
        const char *what() const throw()
        {
            return ("Not Found.");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int num)
{
    for (typename T::iterator it = container.begin(); it != container.end(); it++)
    {
        if (*it == num)
            return (it);
    }
    throw NotFound();
}

#endif
