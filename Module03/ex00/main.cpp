#include "ClapTrap.hpp"

void print_ClapTraps(ClapTrap& claptrap)
{
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "| Name : " << claptrap.getName() << " | HitPoint : " << claptrap.getHitPoints() << " | EnergyPoints : " << claptrap.getEnergyPoints() << " | AttackDamage : " << claptrap.getAttackDamage() << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}

int main(void)
{
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
    return (0);
}