#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string const   _name;
        AMateria            *inv[4];

    public:
        Character();
        Character(std::string name);
        ~Character();
        Character(const Character &src);
        Character &operator=(const Character &src);

        std::string const &getName() const;
        void    equip(AMateria *m);
        void    unequip(int idx);
        void    use(int idx, ICharacter &target);
};

#endif
