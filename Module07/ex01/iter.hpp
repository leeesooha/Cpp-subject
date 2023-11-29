#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T *arrayPtr, T size, T f)
{
    for (size_t i = 0; i < size; i++)
        f(arrayPtr[i]);
}

#endif