#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

void print_ClapTraps(ClapTrap& claptrap)
{
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "| Name : " << claptrap.getName() << " | HitPoint : " << claptrap.getHitPoints() << " | EnergyPoints : " << claptrap.getEnergyPoints() << " | AttackDamage : " << claptrap.getAttackDamage() << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}

int main(void)
{
//------------------------ClapTrap test---------------------//
    ClapTrap A("A");
    ClapTrap B("B");

    print_ClapTraps(A);
    print_ClapTraps(B);

    A.attack(B.getName());
    B.takeDamage(9);
    B.attack(A.getName());
    A.takeDamage(1);
    B.takeDamage(1);
    B.attack(A.getName());

    print_ClapTraps(A);
    print_ClapTraps(B);
    std::cout << std::endl << std::endl;


//------------------------ScavTrap test---------------------//
    ScavTrap C("C");
    ScavTrap D("D");
    C.attack("D");
    D.takeDamage(2);

    print_ClapTraps(C);
    print_ClapTraps(D);
    C.guardGate();
    D.guardGate();


//----정적바인딩----//
    // ClapTrap *ptr_C = &C;
    // ptr_C->attack("B");        //ClapTrap (베이스클래스)에 함수 호출됨, 베이스클래스에 attack을 가상함수로 만들어 주지 않았기 때문에 정적바인딩 되어 베이스클래스에 멤버변수가 호출되었음, 그러나 ScavTrap이 베이스클래스 속성을 직접수정하기에 데미지는 ScavTrap이 바꾼대로 바꿔줘 있음
    // C.attack("B");              //이렇게 명시하면 파생클래스 멤버함수 호출됨.

//----동적바인딩----//
                                //위 정적바인딩 예시코드는 바꾸지 않고, 베이스클래스의 attack을 virtual로 지정하면 동적바인딩 되어 부모클래스에 포인터에 자식클래스가 들어가더라고 알아서 자식클래스의 멤버함수를 호출한다.
                                //그런데 segfault 에러뜸 , 후에 더 공부 해야함.
    return (0);
}