#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("DefaultType")
{
	std::cout << "[AMateria] " << this->_type << " Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << "[AMateria] " << this->_type << " Constructor called" << std::endl;
	this->_type = type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "[AMateria] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "[AMateria] " << "Copy constructor called" << std::endl;
	*this = other;
}

AMateria::~AMateria()
{
	std::cout << "[AMateria] " << " Destructor called" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "[AMateria] " << "AMateria's \'use\' function called" << std::endl;
}

void AMateria::setSize(unsigned int i)
{
	this->_size = i;
}

void AMateria::setOffset(unsigned int i)
{
	this->_offset = i;
}