#include "iter.hpp"
#include "print.hpp"
#include <iostream>

int main(void)
{
    int intArray[10];
    for (size_t i = 0; i < 10; i++)
        intArray[i] = i;
    ::iter<int>(intArray, 10, print);

    char charArray[10];
    for (size_t i = 0; i < 10; i++)
        charArray[i] = 'a' + i;
    ::iter<char>(charArray, 10, print);
    return (0);
}
