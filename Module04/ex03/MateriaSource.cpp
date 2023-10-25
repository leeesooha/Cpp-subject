#include "MateriaSource.hpp"

// virtual ~MateriaSource() {}
// virtual void learnMateria(AMateria*) = 0;
// virtual AMateria* createMateria(std::string const & type) = 0;

MateriaSource::MateriaSource() : IMateriaSource()
{
	this->_offset = 0;
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
		(this->_inventory)[i] = NULL;
	std::cout << "[MateriaSource] " << " Default constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "[MateriaSource] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_offset = other._offset;
		for (size_t i = 0; i < IVENTORY_SIZE; i++)
			(this->_inventory)[i] = (other._inventory)[i];
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
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
	{
		if ((this->_inventory)[i] != NULL)
			delete ((this->_inventory)[i]);
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if ((this->_inventory)[this->_offset] != NULL)
		delete (this->_inventory)[this->_offset];
	(this->_inventory)[this->_offset] = NULL;
	(this->_inventory)[this->_offset] = materia;
	if (this->_offset == IVENTORY_SIZE - 1)
		(this->_offset = 0);
	else
		(this->_offset)++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
	{
		if ((this->_inventory)[i] != NULL \ 
			&& std::strcmp(type.c_str(), (this->_inventory)[i]->getType().c_str()) == 0)
			return ((this->_inventory)[i]->clone());
	}
	return (NULL);
}