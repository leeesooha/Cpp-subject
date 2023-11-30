#ifndef PRINT_HPP
#define PRINT_HPP

#include <cstring>
#include <iostream>

template <typename T>
void print(T const &arg)
{
    std::cout << arg << std::endl;
}

#endif