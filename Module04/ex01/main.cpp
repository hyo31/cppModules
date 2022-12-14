#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal *Animals[6];
    for (int i = 0; i < 6; i++)
    {
        if (i % 2)
            Animals[i] = new Dog();
        else
            Animals[i] = new Cat();
    }
    std::cout << "----------------\n";
    for (int i = 0; i < 6; i++)
    {
        std::cout << Animals[i]->getType() << ": ";
        Animals[i]->makeSound();
    }
    std::cout << "----------------\n";
    for (int i = 0; i < 6; i++)
        delete Animals[i];
    std::cout << "----------------\n";
    Cat *a = new Cat();
    std::cout << a->getIdea(5) << std::endl;
    a->setIdea(5, "play");
    Cat *b = new Cat(*a);
    std::cout << b->getIdea(5) << std::endl;
    return 0;
}