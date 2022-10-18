#include "easyfind.hpp"

int main()
{
    std::vector<int>    intVector;
    int                 Array[] = {3, 4, 2, 5, 2, 7, 9, 1, 3};

    for (int i = 0; i < 9; i++)
        intVector.push_back(Array[i]);
    for (std::vector<int>::iterator it = intVector.begin(); it != intVector.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
    try
    {
        std::cout << *easyfind(intVector, 0) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
