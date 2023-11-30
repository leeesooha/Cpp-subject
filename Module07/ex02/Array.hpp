#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstring>

template <typename T>
void Array(T *arrayPtr, size_t size, void (*f)(T&))
{
    for (size_t i = 0; i < size; i++)
        f(arrayPtr[i]);
}

# include "Array.tpp"
#endif