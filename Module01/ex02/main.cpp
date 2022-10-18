#include <string>
#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "string adress:        " << &string << std::endl;
    std::cout << "stringPTR adress:     " << stringPTR << std::endl;
    std::cout << "stringREF address:    " << &stringREF << std::endl;
    std::cout << "string value:         " << string << std::endl;
    std::cout << "stringPTR value:      " << *stringPTR << std::endl;
    std::cout << "stringREF value:      " << stringREF << std::endl;
    return(0);
}
