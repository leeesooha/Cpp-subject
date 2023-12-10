#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"
#include <string>
#include <iostream>

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual AMateria* createMateria(std::string const & type) = 0;

		virtual void learnMateria(AMateria*) = 0;
		virtual bool findMateria(std::string materiaName) = 0;
		virtual bool forgetMateria(std::string materiaName) = 0;
};

#endif