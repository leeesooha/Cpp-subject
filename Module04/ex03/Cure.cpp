#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	// std::cout << "[Cure] " << this->_type << " Default constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	// std::cout << "[Cure] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Cure::Cure(const Cure& other) : AMateria()
{
	// std::cout << "[Cure] " << "Copy constructor called" << std::endl;
	*this = other;
}

Cure::~Cure()
{
	// std::cout << "[Cure] " << " Destructor called" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *clone_AMateria = new Cure(*this);
	return (clone_AMateria);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
