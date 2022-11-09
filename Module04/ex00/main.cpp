#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Cat* i = new Cat();
    const Animal* j = new Dog();
    const WrongCat* k = new WrongCat();
    const WrongAnimal* l = new WrongCat();
    const Cat *copy = new Cat(*i);
    const Cat *copy2;
    copy2 = copy;
    std::cout << "----------------\n";
    std::cout << i->getType() << " " << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    std::cout << copy2->getType() << " " << std::endl;
    std::cout << "----------------\n";
    i->makeSound(); // Cat
    j->makeSound(); // Dog/Animal
    k->makeSound(); // Wrong cat
    l->makeSound(); // Wrong cat/animal
    copy2->makeSound();
    meta->makeSound();
    std::cout << "----------------\n";
    delete(i);
    delete(j);
    delete(k);
    delete(meta);
    return 0;
}