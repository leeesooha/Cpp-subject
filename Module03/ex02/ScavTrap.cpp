#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ScavTrap] " << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap()
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ScavTrap] " << this->_name << " Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[ScavTrap] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &other)
{
	*this = other;
	std::cout << "[ScavTrap] " << "Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << this->_name << " Destructor called" << std::endl;
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

void ScavTrap::guardGate()
{
	std::cout << this->_name << " is in gatekeeper mode" << std::endl;
}