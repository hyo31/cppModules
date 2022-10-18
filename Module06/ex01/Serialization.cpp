#include "Serialization.hpp"

uintptr_t   serialize(Data *ptr)
{
    return ((uintptr_t)(void*)ptr);
}

Data        *deserialize(uintptr_t num)
{
    return ((Data*)(uintptr_t)num);
}
