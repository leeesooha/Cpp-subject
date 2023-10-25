#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>
#include <iostream>

class AMateria
{
	protected:
		std::string _type;
		AMateria *_materias;
		unsigned int _offset;
		unsigned int _size;
	public:
		AMateria();
		AMateria(const AMateria& other);
		virtual AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		void setSize(unsigned int i);
		void setOffset(unsigned int i);
};

#endif