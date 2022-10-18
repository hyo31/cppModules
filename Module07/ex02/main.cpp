#include "Array.hpp"

int main()
{
    Array<int>			intArray;
	Array<std::string>	stringArray(6);
	Array<std::string>	otherStringArray;

	stringArray[0] = "Hi";
	stringArray[1] = "Hoi";
	stringArray[2] = "Hoe gaat 't?";
	stringArray[3] = "Prima, met jou?";
	stringArray[4] = "Prima";
	stringArray[5] = "Doei!";
	
    std::cout << intArray.size() << std::endl;
	std::cout << stringArray.size() << std::endl;
	
    otherStringArray = stringArray;
	otherStringArray[3] = "*******";
    Array<std::string>  copyStringArray(stringArray);
    stringArray[0] = "Hallo";

    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
        std::cout << stringArray[i] << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
        std::cout << otherStringArray[i] << std::endl;
    std::cout << std::endl;
    for (int i = 0; i < 6; i++)
        std::cout << copyStringArray[i] << std::endl;
    std::cout << std::endl;
	try
	{
		std::cout << stringArray[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << stringArray[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
    return (0);
}
