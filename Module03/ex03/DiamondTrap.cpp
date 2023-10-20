#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	ClapTrap::_name += "_clap_name";
	this->_name = "defaultName";
	this->_energyPoints = ScavTrap::_scavEnergyPoints;
	std::cout << "[DiamondTrap] " << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = name;
	this->_energyPoints = ScavTrap::_scavEnergyPoints;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "[DiamondTrap] " << this->_name << " Constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::_name = other._name + "_clap_name";
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "[DiamondTrap] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = other;
	std::cout << "[DiamondTrap] " << "Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] " << this->_name << " Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap has no HitPoint" << std::endl;
	else
		std::cout << "Is my name " << this->_name << " or " << ClapTrap::_name << " ?" << std::endl;
}

std::string DiamondTrap::getName()
{
	return (this->_name);
}