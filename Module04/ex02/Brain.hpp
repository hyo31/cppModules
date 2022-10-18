#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        std::string idea[100];

    public:
        Brain();
        Brain(Brain const &copy);
        Brain &operator=(Brain const &copy);
        ~Brain();

        void setIdea(int i, std::string newIdea);
        std::string const getIdea(int num)const;
};

#endif
