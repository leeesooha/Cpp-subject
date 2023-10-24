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
		AMateria *_inventory[IVENTORY_SIZE];
		AMateria *_copyMateriaSource;
		unsigned int _copyCount;
	public:
		virtual ~MateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif