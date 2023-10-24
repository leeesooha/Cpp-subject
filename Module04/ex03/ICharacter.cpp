#include "ICharacter.hpp"

ICharacter::ICharacter()
{
	std::cout << "[ICharacter] " << this->_name << " Default constructor called" << std::endl;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
	std::cout << "[ICharacter] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		// this->_type = other._type;
	}
	return (*this);
}

ICharacter::ICharacter(const ICharacter& other)
{
	std::cout << "[ICharacter] " << "Copy constructor called" << std::endl;
	*this = other;
}

ICharacter::~ICharacter()
{
	std::cout << "[ICharacter] " << " Destructor called" << std::endl;
}
