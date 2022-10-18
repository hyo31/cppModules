#include "harl.hpp"

int main()
{
    harl test;

    test.complain("DEBUG");
    test.complain("INFO");
    test.complain("WARNING");
    test.complain("ERROR");
    return (0);
}