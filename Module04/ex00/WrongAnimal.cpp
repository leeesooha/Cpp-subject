#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("DefaultType")
{
	std::cout << "[WrongAnimal] " << "Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "[WrongAnimal] " << " Constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "[WrongAnimal] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "[WrongAnimal] " << "Copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] " << " Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "..." << std::endl;
}