#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void print_ClapTraps(DiamondTrap& diamondtrap)
{
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "| Name : " << diamondtrap.getName() << " | HitPoint : " << diamondtrap.getHitPoints() << " | EnergyPoints : " << diamondtrap.getEnergyPoints() << " | AttackDamage : " << diamondtrap.getAttackDamage() << " |" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}

int main(void)
{
    DiamondTrap G("G");
    print_ClapTraps(G);
    G.attack("H");
    G.whoAmI();
    G.takeDamage(10);

    std::cout << std::endl << std::endl;
    return (0);
}