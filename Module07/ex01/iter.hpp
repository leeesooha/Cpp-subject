#ifndef ITER_HPP
#define ITER_HPP

#include <cstring>

template <typename T>
void iter(T *arrayPtr, size_t size, void (*f)(const T&))
{
    for (size_t i = 0; i < size; i++)
        f(arrayPtr[i]);
}

#endif