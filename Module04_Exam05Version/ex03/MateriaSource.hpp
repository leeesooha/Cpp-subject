#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

#define IVENTORY_SIZE 4

class MateriaSource : public IMateriaSource
{
	private :
		AMateria *_srcInventory[IVENTORY_SIZE];
		std::vector<AMateria *> _testInventory;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource();
		virtual AMateria* createMateria(std::string const & type);

		virtual void learnMateria(AMateria* materia);
		virtual bool findMateria(std::string materiaName);
		virtual bool forgetMateria(std::string materiaName);
};

#endif