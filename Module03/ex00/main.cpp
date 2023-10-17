#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap A("A");
    ClapTrap B("B");

    std::cout << "A info: " << "Name : " << A.getName() << "Hitpoints : " << A.getHitPoints() << "Energypoints : " << A.getEnergyPoints() << << std::endl;
    A.attack(B.getName());

    return (0);
}