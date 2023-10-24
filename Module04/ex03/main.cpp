#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void leak_check(void)
{
    system("leaks interface");
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
    // Ice ice;
    // std::cout << ice.getType() << std::endl;
    // AMateria* amateria_ptr = ice.clone();
    // if (amateria_ptr)
    //     ;
    // delete amateria_ptr;
    // //ice 멤버함수 2개중 하나인 clone()완료
    return (0);
}