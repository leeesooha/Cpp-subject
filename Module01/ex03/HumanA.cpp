#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA() : Human_name(""), Human_club(NULL)
{
}

HumanA::HumanA(std::string name, Weapon &club) : Human_name(name), Human_club(&club)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	if (HumanA::Human_club == NULL)
		return ;
	std::cout << HumanA::Human_name << " attacks with their ";
	std::cout << HumanA::Human_club->getType() << std::endl;
}