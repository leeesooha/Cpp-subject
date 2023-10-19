#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[FragTrap] " << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap()
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[FragTrap] " << this->_name << " Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[FragTrap] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

FragTrap::FragTrap(const FragTrap &other)
{
	*this = other;
	std::cout << "[FragTrap] " << "Copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << this->_name << " Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitPoints == 0)
		std::cout << "FragTrap has no HitPoint" << std::endl;
	else
		std::cout << this->_name << " Let's high five!" << std::endl;
}