#include "MateriaSource.hpp"

// virtual ~MateriaSource() {}
// virtual void learnMateria(AMateria*) = 0;
// virtual AMateria* createMateria(std::string const & type) = 0;

MateriaSource::MateriaSource() : IMateriaSource()
{
	this->_copyCount = 0;
	std::cout << "[MateriaSource] " << " Default constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "[MateriaSource] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "[MateriaSource] " << "Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "[MateriaSource] " << " Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria*)
{

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	
}