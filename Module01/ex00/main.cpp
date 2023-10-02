#include "Zombie.hpp"

int main(void)
{
	std::string name1 = "one";
	std::string name2 = "two";

	Zombie* newzombie;
	newzombie = newZombie(name1);
	newzombie->announce();
	delete newzombie;

	randomChump(name2);
	return (0);
}