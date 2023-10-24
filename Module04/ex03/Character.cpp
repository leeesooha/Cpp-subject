#include "Character.hpp"

// 	std::string _name;
// public:
// 	virtual ~Character() {}
// 	virtual std::string const & getName() const = 0;
// 	virtual void equip(AMateria* m) = 0;
// 	virtual void unequip(int idx) = 0;
// 	virtual void use(int idx, Character& target) = 0;

Character::Character() : ICharacter()
{
	this->_name = "DefaultCharacter";
	std::cout << "[Character] " << this->_name << " Default constructor called" << std::endl;
}

Character::Character(const std::string name)
{
	std::cout << "[Character] " << this->_name << " Constructor called" << std::endl;
	this->_name = name;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "[AMateria] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
	}
	return (*this);
}

Character::Character(const Character& other)
{
	std::cout << "[AMateria] " << "Copy constructor called" << std::endl;
	*this = other;
}

Character::~Character()
{
	std::cout << "[Character] " << " Destructor called" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{

}

void Character::unequip(int idx)
{

}

void Character::use(int idx, Character& target)
{

}
