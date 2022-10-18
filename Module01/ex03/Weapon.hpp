#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon
{
    public:
        const std::string    &getType(void);
        void    setType(const std::string &type);

        Weapon(std::string type);

    private:
        std::string type;
};

#endif