#include "Weapon.hpp"

Weapon::Weapon() : _type("")
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(std::string type)
{
	Weapon::_type = type;
}

const std::string& Weapon::getType()
{
	std::string& ref_weapon = Weapon::_type;
	return (ref_weapon);
}

void Weapon::setType(std::string new_weapon)
{
	Weapon::_type = new_weapon;
}
