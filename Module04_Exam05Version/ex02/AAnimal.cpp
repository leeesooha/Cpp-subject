#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("DefaultType")
{
	std::cout << "[AAnimal] " << "Default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "[AAnimal] " << " Constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	std::cout << "[AAnimal] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "[AAnimal] " << "Copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] " << " Destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}
