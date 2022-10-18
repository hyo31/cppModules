#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created" << std::endl;
    const std::string idea[4] = {"eat", "sleep", "poop", "make noise"};
    int j = 0;
    for (int i = 0; i < 100; i++)
    {
        this->idea[i] = idea[j];
        j++;
        if (j == 5)
            j = 0;
    }
}

Brain::Brain(Brain const &copy)
{
    for(int i = 0; i < 100; i++)
        this->idea[i] = copy.getIdea(i);
}

Brain &Brain::operator=(const Brain &copy)
{
    for(int i = 0; i < 100; i++)
        this->idea[i] = copy.getIdea(i);
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain deleted" << std::endl;
}

void    Brain::setIdea(int i, std::string newIdea)
{
    if (i < 100)
        this->idea[i] = newIdea;
    else
        std::cout << "There is only space for 100 ideas" << std::endl;
}

std::string const Brain::getIdea(int num) const
{
    if (num < 100)
        return(this->idea[num]);
    else
    {
        std::cout << "There are only 100 ideas" << std::endl;
        return(NULL);
    }
}
