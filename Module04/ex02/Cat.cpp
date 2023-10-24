#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "[Cat] " << "Default constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain();
		*this->_brain = *(other.getBrain());
	}
	std::cout << "[Cat] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

Cat::Cat(const Cat &other) : AAnimal()
{
	this->_brain = new Brain();
	std::cout << "[Cat] " << "Copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat()
{
	delete (this->_brain);
	std::cout << "[Cat] " << " Destructor called" << std::endl;
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