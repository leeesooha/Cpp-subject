#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "[Cat] " << "Default constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "[Cat] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "[Cat] " << "Copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	std::cout << "[Cat] " << " Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow~" << std::endl;
}