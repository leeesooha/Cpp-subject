#include "Animal.hpp"

Animal::Animal() : _type("DefaultType")
{
	std::cout << "[Animal] " << "Default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "[Animal] " << " Constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Animal::Animal(const Animal &other)
{
	std::cout << "[Animal] " << "Copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal()
{
	std::cout << "[Animal] " << " Destructor called" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "..." << std::endl;
}