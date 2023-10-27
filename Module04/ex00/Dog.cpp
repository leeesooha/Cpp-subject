#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "[Dog] " << "Default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "[Dog] " << "Copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	std::cout << "[Dog] " << " Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark!!!" << std::endl;
}