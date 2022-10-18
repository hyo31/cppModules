#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

typedef struct
{
    unsigned int    num;
    std::string     str;
}Data;

uintptr_t   serialize(Data *ptr);
Data        *deserialize(uintptr_t num);

#endif
