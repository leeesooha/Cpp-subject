#include "Zombie.hpp"

int main(void)
{
	std::string name_for_heap = "one";
	std::string name_for_stack = "two";

	Zombie* newzombie;
	newzombie = newZombie(name_for_heap);
	newzombie->announce();
	delete newzombie;

	randomChump(name_for_stack);
	return (0);
}