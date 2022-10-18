#include "../inc/Conversion.hpp"

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Invalid amount of arguments." << std::endl;
        return (-1);
    }
    Conversion conversed(argv[1]);
    conversed.Print();
    return (0);
}
