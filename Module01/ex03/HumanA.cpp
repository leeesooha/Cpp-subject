#include "HumanA.hpp"
#include "Weapon.hpp"

// HumanA::HumanA()
// {
// }
HumanA::HumanA(std::string name, Weapon club) : Human_name(name), Human_club(club)
{
}
HumanA::~HumanA()
{

}

void HumanA::attack()
{
	std::cout << HumanA::Human_name << " attacks with their ";
	std::cout << HumanA::Human_club.getType() << std::endl;
}