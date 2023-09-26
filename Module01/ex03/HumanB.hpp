#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public :
		HumanB();
		HumanB(std::string name, Weapon &club);
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &club);
	private :
		std::string Human_name;
		Weapon *Human_club;
};

#endif