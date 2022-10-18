#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

Base    *generate()
{
    int num;

    num = rand() % 3;
    if (!num)
        return (new A());
    else if (num == 1)
        return (new B());
    else if (num == 2)
        return (new C());
    return NULL;
}

void    identify(Base *p)
{
    if (dynamic_cast<A *>(p))
		std::cout << "A, ";
	else if (dynamic_cast<B *>(p))
		std::cout << "B, ";
	else if (dynamic_cast<C *>(p))
		std::cout << "C, ";
}

void    identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
	    std::cout << "A" << std::endl;
    }
    catch (...)
    {}
    try
    {
        B &b = dynamic_cast<B &>(p);
	    std::cout << "B" << std::endl;
    }
    catch (...)
    {}
    try
    {
        C &c = dynamic_cast<C &>(p);
	    std::cout << "C" << std::endl;
    }
    catch (...)
    {}
}

int     main()
{
    Base    *abc;
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        abc = generate();
        identify(abc);
        identify(*abc);
    }
    return (0);
}
