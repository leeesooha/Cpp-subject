#include "HumanB.hpp"
#include "Weapon.hpp"

// HumanB::();
// {
// }
HumanB::HumanB(Weapon &club) : Human_weapon(club)
{
}
HumanB::~HumanB()
{

}

void HumanB::attack()
{
	std::cout << HumanB::Human_name << " attacks with their ";
	std::cout << HumanB::Human_weapon.getType() << std::endl;
}