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

void FragTrap::attack(const std::string& target)
{
	if (this->_hitPoints != 0 && this->_energyPoints != 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "FragTrap " << this->_name << " take "<< amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= amount)
	{
		this->_hitPoints += amount;
		this->_energyPoints -= amount;
		std::cout << "FragTrap " << this->_name <<  " repair "<< amount << " points" << std::endl;
	}
	else
		std::cout << "FragTrap " << this->_name << " doesn't have enough energy" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " Let's high five!" << std::endl;
}