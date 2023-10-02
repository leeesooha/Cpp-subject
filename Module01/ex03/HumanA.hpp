#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public :
		HumanA();
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack();
	private :
		std::string _name;
		int _heapAllocate;
		Weapon *_weapon;
};

#endif