#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	public :
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string& getType();
		void setType(std::string new_weapon);
	private :
		std::string _type;
};

#endif