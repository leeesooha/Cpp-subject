#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <string>
#include <iostream>

class Serializer
{
    public :
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer& other);
        virtual ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif