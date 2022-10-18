#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
    public:
        void    announce(void);

        Zombie(std::string new_name);
        ~Zombie(void);

    private:
        std::string new_name;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif