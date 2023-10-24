#include "AMateria.hpp"
#include "Ice.hpp"

void leak_check(void)
{
    system("leaks interface");
}

int main(void)
{
    atexit(leak_check);

    Ice ice;
    std::cout << ice.getType() << std::endl;
    AMateria* amateria_ptr = ice.clone();
    if (amateria_ptr)
        ;
    delete amateria_ptr;
    //ice 멤버함수 2개중 하나인 clone()완료
    return (0);
}