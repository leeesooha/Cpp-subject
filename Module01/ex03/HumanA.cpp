#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA() : _name(std::string("WHO_AM_I")), _weapon(NULL)
{
	_weapon = new Weapon("default spiked club");
	_heapAllocate = 1;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(&weapon)
{
	_heapAllocate = 0;
}

HumanA::~HumanA()
{
	if (_heapAllocate == 1)
	{
		delete _weapon;
		std::cout << "default spiked club is gone" << std::endl;
	}
}

void HumanA::attack()
{
	std::cout << HumanA::_name << " attacks with their ";
	std::cout << HumanA::_weapon->getType() << std::endl;
}