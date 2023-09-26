#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::setZombie(std::string name)
{
	Zombie::zombie_name = name;
}

Zombie::~Zombie()
{
	std::cout << Zombie::zombie_name;
	std::cout << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << Zombie::zombie_name;
	std::cout << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}