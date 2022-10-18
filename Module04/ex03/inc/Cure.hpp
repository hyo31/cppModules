#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure &src);
        Cure &operator=(const Cure &src);

        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif