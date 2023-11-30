#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <cstring>

template <typename T>
void Array(T *arrayPtr, size_t size, void (*f)(T&))
{
    for (size_t i = 0; i < size; i++)
        f(arrayPtr[i]);
}

// array_ptr = new T[0];
#endif