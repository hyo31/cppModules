#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: virtual public Animal
{
    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        virtual ~Cat();

        void    makeSound()const;
};

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &copy);
        WrongCat &operator=(const WrongCat &copy);
        ~WrongCat();

        void    makeSound()const;
};

#endif
