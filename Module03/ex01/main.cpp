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
//------------------------ScavTrap test---------------------//
    ScavTrap C("C");
    ScavTrap D("D");
    C.attack("D");
    D.takeDamage(2);

    print_ClapTraps(C);
    print_ClapTraps(D);
    C.guardGate();
    D.guardGate();

    return (0);
}