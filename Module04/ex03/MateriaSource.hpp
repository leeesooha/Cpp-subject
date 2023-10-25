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
		unsigned int _offset;
	public:
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* materia);
		virtual AMateria* createMateria(std::string const & type);
};

#endif