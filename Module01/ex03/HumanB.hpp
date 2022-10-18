#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        void    setWeapon(Weapon &type);
        void    attack(void);

    private:
        std::string _name;
        Weapon  *weapon;
};

#endif