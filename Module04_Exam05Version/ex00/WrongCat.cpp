#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "[WrongCat] " << "Default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "[WrongCat] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	std::cout << "[WrongCat] " << "Copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] " << " Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow~" << std::endl;
}