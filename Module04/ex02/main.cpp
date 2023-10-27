#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <cstdlib>

void leak_check(void)
{
    std::system("leaks a.out");
}

int main(void)
{
    std::atexit(leak_check);

    AAnimal* dog = new Dog;
    dog->makeSound();
    delete dog;
    return (0);
}
