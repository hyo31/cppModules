#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	std::cout << "top : " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top : " << mstack.top() << std::endl;
	std::cout << "size : " << mstack.size() << std::endl;
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	MutantStack<int>::iterator it = mstack.begin();
	for (; it != mstack.end(); it++)
	{
		std::cout << "value : " << *it << std::endl;
	}

    std::cout << std::endl;

    std::list<int> list;

	list.push_back(1);
	list.push_back(2);
	std::cout << "back : " << list.back() << std::endl;
	list.pop_back();
	std::cout << "back : " << list.back() << std::endl;
	std::cout << "size : " << list.size() << std::endl;
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	std::list<int>::iterator it2 = list.begin();
	for (; it2 != list.end(); it2++)
	{
		std::cout << "value : " << *it2 << std::endl;
	}

    std::cout << std::endl;

    MutantStack<int> mS_copy(mstack);
    MutantStack<int> mS_copy2 = mS_copy;

	mS_copy2.push(6);
	mS_copy2.push(7);
	std::cout << "top : " << mS_copy2.top() << std::endl;
	mS_copy2.pop();
	std::cout << "top : " << mS_copy2.top() << std::endl;
	std::cout << "size : " << mS_copy2.size() << std::endl;
	mS_copy2.push(7);
	mS_copy2.push(8);
	mS_copy2.push(9);
	mS_copy2.push(10);
	MutantStack<int>::iterator it3 = mS_copy2.begin();
	for (; it3 != mS_copy2.end(); it3++)
	{
		std::cout << "value : " << *it3 << std::endl;
	}
    return (0);
}
