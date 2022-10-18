#include "iter.hpp"

void    print_upper(char c)
{
    char C = toupper(c);
    std::cout << "This capital character is: " << C << "!" << std::endl;
}

void    print_string(std::string str)
{
    std::cout << "This string is: " << str << "!" << std::endl;
}

int main()
{
    char *str = (char *)"hello test123!";
    iter(str, 14, print_upper);
    std::string strstr[] = {"Hello", "test", "123", "!"};
    iter(strstr, 4, print_string);
    return (0);
}
