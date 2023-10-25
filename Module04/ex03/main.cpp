#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <stdlib.h>

void leak_check(void)
{
    system("leaks a.out");
}

int main(void)
{
    atexit(leak_check);

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    std::cout << "------------------------------------------------------------------" << std::endl;

    //---------------------------self test case--------------------
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    ICharacter* me2 = new Character("me");
    AMateria* tmp2;
    for (unsigned int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
            tmp2 = src2->createMateria("ice");
        else
            tmp2 = src2->createMateria("cure");
        me2->equip(tmp2);
        if (i >= 4)
            delete tmp2;
    }
    ICharacter* bob2 = new Character("bob");
    me2->use(0, *bob2);
    me2->use(1, *bob2);
    delete bob2;
    delete me2;
    delete src2;
    std::cout << std::endl;
    return (0);
}