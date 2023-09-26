#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	public :
		Zombie();
		~Zombie();
		void announce(void);
		void setZombie(std::string name);

	private :
		std::string zombie_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif