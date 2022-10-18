#include "harl.hpp"

int harl_switch(char *level, harl &test)
{
    std::string actions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         num;
    
    num = -1;
    for (int i = 0; i < 4; i++)
        if (actions[i] == level)
            num = i;
    switch (num)
    {
        case 0:
            test.complain("DEBUG");
        case 1:
            test.complain("INFO");
        case 2:
            test.complain("WARNING");
        case 3:
            test.complain("ERROR");
            break ;
        default:
            std::cout << "Unknown filter" << std::endl;
    }
    return (0);
}

int main(int argc, char **argv)
{
    harl test;

    if (argc != 2)
    {
        std::cout << "No filter given" << std::endl;
        return (1);
    }
    return (harl_switch(argv[1], test));
}