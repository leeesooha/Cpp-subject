#include "Zombie.hpp"

int main(void)
{
	int			NbZombie = 10;
	std::string name = "zombie";
	Zombie* 	zombies = zombieHorde(NbZombie, name);

	if (zombies == NULL)
		return (1);
	for (int i = 0; i < NbZombie; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}