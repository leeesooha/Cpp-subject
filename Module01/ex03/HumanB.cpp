#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB() : Human_name(""), Human_club(NULL)
{
}

HumanB::HumanB(std::string name) : Human_name(name), Human_club(NULL)
{
}

HumanB::HumanB(std::string name, Weapon &club) : Human_name(name), Human_club(&club)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &club)
{
	HumanB::Human_club = &club;
}

void HumanB::attack()
{
	if (HumanB::Human_club == NULL)
	{
		std::cout << "do not have a weapon." << std::endl;
		return ;
	}
	std::cout << HumanB::Human_name << " attacks with their ";
	std::cout << HumanB::Human_club->getType() << std::endl;
}