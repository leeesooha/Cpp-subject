#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal()
{
	std::cout << "[Cat] " << "Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "[Cat] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *(other.getBrain());
	}
	return (*this);
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "[Cat] " << "Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = other;
}

Cat::~Cat()
{
	std::cout << "[Cat] " << " Destructor called" << std::endl;
	delete (this->_brain);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow~" << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (this->_brain);
}

void Cat::setBrain(Brain* brain)
{
	delete (this->_brain);
	this->_brain = brain;
}