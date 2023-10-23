#include "Brain.hpp"

Brain::Brain()
{
	for (size_t i = 0; i < 100; i++)
		this->_ideas[i] = "";
	std::cout << "[Brain] " << "Default constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << "[Brain] " << "Copy assignment operator called" << std::endl;
	return (*this);
}

Brain::Brain(const Brain &other)
{
	std::cout << "[Brain] " << "Copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "[Brain] " << " Destructor called" << std::endl;
}

std::string Brain::getIdeas(const size_t index) const
{
	if (index >= 100)
	{
		return ("Invalid index");
	}
	return (this->_ideas[index]);
}

bool Brain::setIdeas(const size_t index, const std::string ideas)
{
	if (index >= 100)
		return (false);
	this->_ideas[index] = ideas;
	return (true);
}