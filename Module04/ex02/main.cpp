#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //const Animal* meta = new Animal();
    const Animal* i = new Cat();
    const Animal* j = new Dog();
    std::cout << "----------------\n";
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "----------------\n";
    i->makeSound();
    j->makeSound();
    std::cout << "----------------\n";
    //meta->makeSound();
    delete(i);
    delete(j);
    //delete(meta);
    return 0;
}
