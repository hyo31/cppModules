#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
    public:
        Zombie(std::string name);
        Zombie();
        void    announce(void);
        void    set_name(std::string new_name);

        ~Zombie(void);

    private:
        std::string newName;
};

Zombie* zombieHorde(int N, std::string name);

#endif