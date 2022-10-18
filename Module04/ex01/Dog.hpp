#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: virtual public Animal
{
    private:
        Brain *Brain;

    public:
        Dog();
        Dog(const Dog &copy);
        Dog &operator=(const Dog &copy);
        virtual ~Dog();

        void    makeSound()const;
        void setIdea(int i, std::string newIdea);
        std::string getIdea(int i) const;
};

#endif
