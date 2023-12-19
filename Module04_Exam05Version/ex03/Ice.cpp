#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria()
{
	this->_type = "ice";
	// std::cout << "[Ice] " << this->_type << " Default constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	// std::cout << "[Ice] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Ice::Ice(const Ice& other) : AMateria()
{
	// std::cout << "[Ice] " << "Copy constructor called" << std::endl;
	*this = other;
}

Ice::~Ice()
{
	// std::cout << "[Ice] " << " Destructor called" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *clone_AMateria = new Ice(*this);
	return (clone_AMateria);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}