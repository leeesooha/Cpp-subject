#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	public :
		// HumanB();
		HumanB(Weapon& club);
		~HumanB();
		void attack();
	private :
		std::string Human_name;
		Weapon &Human_weapon;
};

#endif