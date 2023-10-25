#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : ICharacter()
{
	this->_name = "DefaultCharacter";
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
		(this->_characterInventory)[i] = NULL;
	std::cout << "[Character] " << this->_name << " Default constructor called" << std::endl;
}

Character::Character(const std::string name)
{
	this->_name = name;
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
		(this->_characterInventory)[i] = NULL;
	std::cout << "[Character] " << this->_name << " Constructor called" << std::endl;
}

Character& Character::operator=(const Character& other)
{
	std::cout << "[AMateria] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (size_t i = 0; i < IVENTORY_SIZE; i++)
		{
			if ((this->_characterInventory)[i] != NULL)
			{
				delete ((this->_characterInventory)[i]);
				(this->_characterInventory)[i] = NULL;
				(this->_characterInventory)[i] = (other._characterInventory)[i]->clone();
			}
		}
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
	for (size_t i = 0; i < IVENTORY_SIZE; i++)
	{
		if ((this->_characterInventory)[i] != NULL)
		{
			delete ((this->_characterInventory)[i]);
			(this->_characterInventory)[i] = NULL;
		}
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

//The equip function's parameter 'AMateria* m' does not free memory when the inventory is full.
void Character::equip(AMateria* m)
{
	size_t idx = 0;

	while (idx < IVENTORY_SIZE && (this->_characterInventory)[idx] != NULL)
		idx++;
	if (idx == IVENTORY_SIZE)
		return ;
	(this->_characterInventory)[idx] = m;
}

//The 'unequip' function does not free the memory of the unequipped 'Materia'.
void Character::unequip(int idx)
{
	if ((idx >= 0 && idx < IVENTORY_SIZE) == false)
		return ;
	(this->_characterInventory)[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= IVENTORY_SIZE)
		return ;
	if ((this->_characterInventory)[idx] == NULL)
		return ;
	(this->_characterInventory)[idx]->use(target);
}
