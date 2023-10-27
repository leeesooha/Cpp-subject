#include "Animal.hpp"
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

    // --------------------subject copy test--------------------
    std::cout << "------------------------subject copy test---------------------" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
    std::cout << std::endl;

    //--------------------subject require test--------------------
    std::cout << "------------------------subject require test------------------" << std::endl;
    Animal *animal[10];
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "Creat " << i << " : ";
        if (i % 2)
            animal[i] = new Dog();
        else
            animal[i] = new Cat();
    }
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++)
        std::cout << "[" << i << "] " << animal[i]->getType() << std::endl;
    std::cout << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << "Delete " << i << " : ";
        delete animal[i];
    }
    std::cout << std::endl;

    //--------------------self test1--------------------
    std::cout << "--------------------------self test1-------------------------" << std::endl;
    Dog *puppy = new Dog();
    Dog *loopy = new Dog();
    Brain *puppy_brain = new Brain();
    puppy_brain->setIdeas(0, "puppy's good ideas");
    puppy_brain->setIdeas(1, "puppy's good bad ideas");
    puppy->setBrain(puppy_brain);
    std::cout << puppy->getBrain()->getIdeas(0) << std::endl;
    std::cout << std::endl;
    *loopy = *puppy;
    std::cout << std::endl;
    delete puppy;
    delete loopy;
    std::cout << std::endl;
    return (0);
}
