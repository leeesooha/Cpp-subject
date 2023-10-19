#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void print_ClapTraps(ClapTrap& claptrap)
{
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "| Name : " << claptrap.getName() << " | HitPoint : " << claptrap.getHitPoints() << " | EnergyPoints : " << claptrap.getEnergyPoints() << " | AttackDamage : " << claptrap.getAttackDamage() << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}

int main(void)
{
//-----------FragTrap--------------------//

    FragTrap E("E");
    FragTrap F("F");
    E.attack("F");
    F.takeDamage(2);

    print_ClapTraps(E);
    print_ClapTraps(F);
    E.highFivesGuys();
    F.highFivesGuys();

    return (0);
}