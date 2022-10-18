#include "Serialization.hpp"

int main()
{
    Data        test;
    uintptr_t   intPtr;
    Data        *newTest;

    test.str = "test string";
    test.num = 123;

    intPtr = serialize(&test);
    std::cout << intPtr << std::endl;
    newTest = deserialize(intPtr);

    std::cout << newTest->str << std::endl;
    std::cout << newTest->num << std::endl;
    return (0);
}
