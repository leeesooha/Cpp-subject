#include "iter.hpp"
#include <iostream>

void increment(int *num)
{
    *num += 3;
}

int main(void)
{
    int array[10];

    for (size_t i = 0; i < 10; i++)
        array[i] = 0;
    std::cout << array << std::endl;
    
    ::iter(array, 10, increment);
    return 0;
}
