#include "Zombie.hpp"

Zombie::Zombie (std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << Zombie::_name;
	std::cout << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << Zombie::_name;
	std::cout << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}