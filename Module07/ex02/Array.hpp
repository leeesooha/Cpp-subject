#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstring>

template <typename T>
class Array
{
    public :
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array& operator=(const Array<T> &other);
        ~Array();
        T& operator[](const long &idex);
        size_t getArraySize() const;
    private :
        T *_arrayPtr;
        size_t _arraySize;
};

#include "Array.tpp"
#endif
