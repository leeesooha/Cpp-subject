#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public :
		HumanA();
		HumanA(std::string name, Weapon &club);
		~HumanA();
		void attack();
	private :
		std::string Human_name;
		Weapon *Human_club;
};

#endif