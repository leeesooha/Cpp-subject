#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << this->_name << " Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = 10;
		this->_energyPoints = 10;
		this->_attackDamage = 0;
	}
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() : ~ClapTrap()
{
	std::cout << this->_name << " Destructor called" << std::endl;
}

std::string ScavTrap::getName()
{
	return (this->_name);
}

unsigned int ScavTrap::getHitPoints()
{
	return (this->_hitPoints);
}

unsigned int ScavTrap::getEnergyPoints()
{
	return (this->_energyPoints);
}

unsigned int ScavTrap::getAttackDamage()
{
	return (this->_attackDamage);
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints != 0 && this->_energyPoints != 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout << "ScavTrap " << this->_name << " take "<< amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints >= amount)
	{
		this->_hitPoints += amount;
		this->_energyPoints -= amount;
		std::cout << "ScavTrap " << this->_name <<  " repair "<< amount << " points" << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy" << std::endl;
}

// void ScavTrap::setAttackDamage(unsigned int amount)
// {
// 	this->_attackDamage = amount;
// }

// std::string ScavTrap::setName(std::string name)
// {
// 	this->_name = name;
// }

// unsigned int ScavTrap::setHitPoints()
// {

// }

// unsigned int ScavTrap::setEnergyPoints()
// {

// }
