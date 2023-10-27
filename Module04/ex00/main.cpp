#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <cstdlib>

void leak_check(void)
{
    std::system("leaks a.out");
}

int main(void)
{
    std::atexit(leak_check);

    //subject test case
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;

    //Wrong Version
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongi = new WrongCat();
    std::cout << wrongi->getType() << " " << std::endl;
    wrongi->makeSound(); //will output the cat sound!
    wrongMeta->makeSound();
    delete wrongMeta;
    delete wrongi;
    std::cout << std::endl;

    std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;
    Animal animal;
    animal.makeSound();
    return (0);
}
