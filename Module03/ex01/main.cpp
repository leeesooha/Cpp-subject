#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap A("A");
    ClapTrap B("B");

    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "A's info-> " << "Name : " << A.getName() << " | Hitpoints : " << A.getHitPoints() << " | Energypoints : " << A.getEnergyPoints() << " | attackdamage : " << A.getAttackDamage() << std::endl;
    std::cout << "B's info-> " << "Name : " << B.getName() << " | Hitpoints : " << B.getHitPoints() << " | Energypoints : " << B.getEnergyPoints() << " | attackdamage : " << B.getAttackDamage() << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    // B.setAttackDamage(2);

    A.attack(B.getName());
    B.takeDamage(9);
    B.attack(A.getName());
    A.takeDamage(1);
    B.takeDamage(1);
    B.attack(A.getName());

    std::cout << "---------------------------------------------------------------------------------" << std::endl;
    std::cout << "A's info-> " << "Name : " << A.getName() << " | Hitpoints : " << A.getHitPoints() << " | Energypoints : " << A.getEnergyPoints() << " | attackdamage : " << A.getAttackDamage() << std::endl;
    std::cout << "B's info-> " << "Name : " << B.getName() << " | Hitpoints : " << B.getHitPoints() << " | Energypoints : " << B.getEnergyPoints() << " | attackdamage : " << B.getAttackDamage() << std::endl;
    std::cout << "---------------------------------------------------------------------------------" << std::endl;

    ScavTrap SA("SA");
    return (0);
}