#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>
#include <iostream>

class Character : public ICharacter
{
	private :
		std::string _name;
		AMateria _inventory[4];
	public:
		Character();
		Character(const std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();
		virtual std::string const& getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, Character& target);
};

#endif