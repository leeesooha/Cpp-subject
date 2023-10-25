#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>
#include <iostream>

#define IVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{
	private :
		AMateria *_srcInventory[IVENTORY_SIZE];
	public:
		MateriaSource();
		MateriaSource(const std::string name);
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(std::string const & type);
};

#endif