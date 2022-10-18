#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        std::string _type;
    public:
        Ice();
        ~Ice();
        Ice(const Ice &src);
        Ice &operator=(const Ice &src);

        virtual AMateria* clone() const;
        void use(ICharacter& target);
};

#endif
