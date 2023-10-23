#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "[Dog] " << "Default constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *(other.getBrain());
	}
	std::cout << "[Dog] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

Dog::Dog(const Dog &other) : Animal()
{
	this->_brain = new Brain();
	std::cout << "[Dog] " << "Copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog()
{
	delete (this->_brain);
	std::cout << "[Dog] " << " Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark Bark!!!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (this->_brain);
}

void Dog::setBrain(Brain* brain)
{
	delete (this->_brain);
	this->_brain = brain;
}