#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public :
		Weapon();
		Weapon(std::string weapon);
		~Weapon();
		const std::string& getType();
		void setType(std::string new_weapon);
	private :
		std::string weapon_Type;
};

#endif