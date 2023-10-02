#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB() : _name("WHO_AM_I"), _weapon(NULL)
{
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon &club) : _name(name), _weapon(&club)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &club)
{
	HumanB::_weapon = &club;
}

void HumanB::attack()
{
	if (HumanB::_weapon == NULL)
	{
		std::cout << "do not have a weapon." << std::endl;
		return ;
	}
	std::cout << HumanB::_name << " attacks with their ";
	std::cout << HumanB::_weapon->getType() << std::endl;
}