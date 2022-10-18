#include "Replace.hpp"

int replace(char **argv, std::string str)
{
    std::ofstream   output;
    int             loc;

    output.open(std::string(argv[1]) += ".replace");
    if (output.fail())
    {
        std::cout << "failed to open output" << std::endl;
        return (1);
    }
    for (int i = 0; i < (int)str.size(); i++)
    {
        loc = str.find(argv[2], i);
        if (loc == i)
        {
            output << argv[3];
            i += std::string(argv[2]).size() - 1;
        }
        else
            output << str[i];
    }
    output.close();
    return (0);
}
