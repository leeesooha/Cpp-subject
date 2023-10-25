#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void leak_check(void)
{
    system("leaks a.out");
}

int main(void)
{
    atexit(leak_check);

    AAnimal* dog = new Dog;
    dog->makeSound();
    delete dog;
    return (0);
}
