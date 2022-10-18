#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    private:
        unsigned int _ep;
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &copy);
        virtual ~ScavTrap();

        void    attack(const std::string &target);
        void    guardGate();
        unsigned int getEp()const;
};

#endif
