#include "Character.hpp"
#include "AMateria.hpp"

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
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
		(this->_inventory)[i] = NULL;
	std::cout << "[Character] " << this->_name << " Default constructor called" << std::endl;
}

Character::Character(const std::string name)
{
	this->_name = name;
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
		(this->_inventory)[i] = NULL;
	std::cout << "[Character] " << this->_name << " Constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "[AMateria] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (size_t i = 0; i < IVENTORY_SIZE; i++)
			(this->_inventory)[i] = (other._inventory[i]);
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
	size_t idx = 0;

	while (idx < IVENTORY_SIZE && (this->_inventory)[idx] != NULL)
		idx++;
	if (idx == IVENTORY_SIZE)
		return ;
	(this->_inventory)[idx] = m;
}

void Character::unequip(int idx)
{
	if ((idx >= 0 && idx < IVENTORY_SIZE) == false)
		return ;
	(this->_inventory)[idx] = NULL;
}

void Character::use(int idx, Character& target)
{
	size_t j = 0;

	while (j < IVENTORY_SIZE)
	{
		if ((this->_inventory)[j] == NULL)
			return ;
		j++;
	}
	if (j == IVENTORY_SIZE)
		return ;
	(this->_inventory)[j]->use(target);
}
