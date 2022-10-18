#include "Span.hpp"

int main()
{
    srand(time(NULL));
    int                 num;
    unsigned int        size = 10000;
    std::vector<int>    vec;
    Span                span(size);

    // try to find longest and shortest numbers with less then 2 numbers in the class
    try
    {
        span.addNumber(42);
        std::cout << span.shortestSpan() << std::endl;
        span.addNumber(42);
        std::cout << span.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    span.print();

    // try to fill the class with numbers
    try
    {
        for (unsigned int i = 1; i < size; i++)
        {
            num = rand() % 2147483647;
            if (rand() % 2)
                num *= -1;
            vec.push_back(num);
        }
        span.addNumber(vec.begin(), vec.end());
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    span.print();
    
    try
    {
        std::cout << "Shortest: " << span.shortestSpan() << std::endl;
        std::cout << "Longest: " << span.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // try to add a number while the class is full
    try
    {
        span.addNumber(42);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
