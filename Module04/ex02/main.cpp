#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <stdlib.h>

void leak_check(void)
{
    system("leaks Brain");
}

int main(void)
{
    atexit(leak_check);

    Animal 
    Animal animal;
    return (0);
}
