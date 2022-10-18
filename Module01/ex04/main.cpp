#include "Replace.hpp"

int main(int argc, char **argv)
{
    std::ifstream   input;
    std::string     str;
    char            c;
    
    if (argc != 4)
    {
        std::cout << "incorrect input" << std::endl;
        return (1);
    }
    input.open(argv[1]);
    if (input.fail())
    {
        std::cout << "failed to open input" << std::endl;
        return (1);
    }
    while (!input.eof() && input >> std::noskipws >> c)
        str += c;
    input.close();
    return (replace(argv, str));
}
