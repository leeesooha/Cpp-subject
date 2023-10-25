#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure& other);
		virtual Cure& operator=(const Cure& other);
		virtual ~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif