#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <cstdlib>

void leak_check(void)
{
    std::system("leaks a.out");
}

int main(void)
{
    std::atexit(leak_check);

    IMateriaSource* src = new MateriaSource();
    Ice* ice1 = new Ice();
    Cure* Cure1 = new Cure();
    Cure* Cure2 = new Cure();
    Cure* Cure3 = new Cure();
    Cure* Cure4 = new Cure();
    Cure* Cure5 = new Cure();

    src->learnMateria(ice1);
    src->learnMateria(Cure1);
    src->learnMateria(Cure2);
    if (src->forgetMateria("cure") == true)
        std::cout << "forget cure" << std::endl;
    else
        std::cout << "fail forget cure" << std::endl;
    src->learnMateria(Cure3);
    src->learnMateria(Cure4);
    src->learnMateria(Cure5);
    if (src->findMateria("ice") == true)
        std::cout << "found ice" << std::endl;
    else
        std::cout << "not found ice" << std::endl;
    // ICharacter* me = new Character("me");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    delete ice1;
    delete Cure1;
    delete Cure2;
    delete Cure3;
    delete Cure4;
    delete Cure5;
    delete src;
    std::cout << "------------------------------------------------------------------" << std::endl;

    //---------------------------self test case--------------------
    // IMateriaSource* src2 = new MateriaSource();
    // src2->learnMateria(new Ice());
    // src2->learnMateria(new Cure());
    // ICharacter* me2 = new Character("me");
    // AMateria* tmp2;
    // for (unsigned int i = 0; i < 10; i++)
    // {
    //     if (i % 2 == 0)
    //         tmp2 = src2->createMateria("ice");
    //     else
    //         tmp2 = src2->createMateria("cure");
    //     if (((Character *)me2)->IsFull() == true)
    //         delete tmp2;
    //     else
    //         me2->equip(tmp2);
    // }
    // ICharacter* bob2 = new Character("bob");
    // me2->use(0, *bob2);
    // me2->use(1, *bob2);
    // delete bob2;
    // delete me2;
    // delete src2;
    // std::cout << std::endl;

    return (0);
}