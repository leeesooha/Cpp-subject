#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <stdlib.h>

void leak_check(void)
{
    system("leaks Animal | grep \"leaks for \"");
}

int main(void)
{
    atexit(leak_check);
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    // ...
    delete meta;
    delete i;
    delete j;
    return (0);
}
