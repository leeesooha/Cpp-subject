#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal()
{
	std::cout << "[Dog] " << "Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "[Dog] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *(other.getBrain());
	}
	return (*this);
}

Dog::Dog(const Dog &other) : Animal()
{
	std::cout << "[Dog] " << "Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = other;
}

Dog::~Dog()
{
	std::cout << "[Dog] " << " Destructor called" << std::endl;
	delete (this->_brain);
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