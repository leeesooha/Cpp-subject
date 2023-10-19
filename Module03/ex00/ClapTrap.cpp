#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default")
{
	std::cout << "Default constructor called" << std::endl;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << this->_name << " Constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " Destructor called" << std::endl;
}

std::string ClapTrap::getName()
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints()
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints != 0 && this->_energyPoints != 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " take "<< amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= amount)
	{
		this->_hitPoints += amount;
		this->_energyPoints -= amount;
		std::cout << "ClapTrap " << this->_name <<  " repair "<< amount << " points" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy" << std::endl;
}
