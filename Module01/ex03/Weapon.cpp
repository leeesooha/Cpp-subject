#include "Weapon.hpp"

Weapon::Weapon() : weapon_Type("NONE")
{
}

Weapon::~Weapon()
{
}

Weapon::Weapon(std::string weapon)
{
	Weapon::weapon_Type = weapon;
}

const std::string& Weapon::getType()
{
	std::string& ref_weapon = Weapon::weapon_Type;
	return (ref_weapon);
}

void Weapon::setType(std::string new_weapon)
{
	Weapon::weapon_Type = new_weapon;
}
