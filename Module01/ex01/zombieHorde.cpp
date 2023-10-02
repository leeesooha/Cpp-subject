#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
		return (NULL);
	Zombie *zombies = new Zombie[N];
	std::ostringstream ss;
	std::string str;

	for (int i = 0; i < N; i++)
	{
		ss.str("");
    	ss << i;
    	str = ss.str();
		zombies[i].setZombie(name + "[" + str + "]");
	}
	return zombies;
}