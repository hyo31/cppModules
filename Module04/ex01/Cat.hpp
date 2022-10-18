#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: virtual public Animal
{
    private:
        Brain *Brain;

    public:
        Cat();
        Cat(const Cat &copy);
        Cat &operator=(const Cat &copy);
        virtual ~Cat();

        void    makeSound()const;
        void setIdea(int i, std::string newIdea);
        std::string getIdea(int i) const;
};

#endif
