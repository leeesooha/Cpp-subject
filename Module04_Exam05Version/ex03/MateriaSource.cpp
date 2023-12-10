#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource()
{
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
		(this->_srcInventory)[i] = NULL;
	// std::cout << "[MateriaSource] " << " Default constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	// std::cout << "[MateriaSource] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (size_t i = 0; i < IVENTORY_SIZE; i++)
			(this->_srcInventory)[i] = (other._srcInventory)[i];
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	// std::cout << "[MateriaSource] " << "Copy constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	// std::cout << "[MateriaSource] " << " Destructor called" << std::endl;
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
	{
		if ((this->_srcInventory)[i] != NULL)
		{
			delete ((this->_srcInventory)[i]);
			(this->_srcInventory)[i] = NULL;
		}
	}
	for (std::vector<AMateria *>::iterator it = _testInventory.begin(); it != _testInventory.end(); it++)
	{
		delete (*it);
	}
}

void MateriaSource::learnMateria(AMateria* materia)
{
	this->_testInventory.push_back(materia->clone());
	// size_t idx = 0;
	// size_t jdx = 0;

	// while (idx < IVENTORY_SIZE && (this->_srcInventory)[idx] != NULL)
	// 	idx++;
	// if (idx == IVENTORY_SIZE)
	// {
	// 	delete materia;
	// 	return ;
	// }
	// while (jdx < IVENTORY_SIZE && &(this->_srcInventory)[jdx] != &materia)
	// 	jdx++;
	// if (jdx != IVENTORY_SIZE)
	// 	return ;
	// (this->_srcInventory)[idx] = materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
	{
		if ((this->_srcInventory)[i] != NULL \
			&& std::strcmp(type.c_str(), (this->_srcInventory)[i]->getType().c_str()) == 0)
			return ((this->_srcInventory)[i]->clone());
	}
	return (NULL);
}

bool MateriaSource::findMateria(std::string materiaName)
{
	for(std::vector<AMateria *>::iterator it = _testInventory.begin(); it != _testInventory.end(); it++)
	{
		if ((*it)->getType() == materiaName)
			return (true);
	}
	return (false);
}

bool MateriaSource::forgetMateria(std::string materiaName)
{
	for(std::vector<AMateria *>::iterator it = _testInventory.begin(); it != _testInventory.end(); it++)
	{
		if ((*it)->getType() == materiaName)
		{	
			delete (*it);
			_testInventory.erase(it);
			return (true);
		}
	}
	return (false);
}