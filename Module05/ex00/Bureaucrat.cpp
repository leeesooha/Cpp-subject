#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultType")
{
	std::cout << "[Bureaucrat] " << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	std::cout << "[Bureaucrat] " << " Constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "[Bureaucrat] " << "Copy assignment operator called" << std::endl;
	if (this != &other)
	// {
	// 	this->_name = other._name; //const 처리
	// }
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "[Bureaucrat] " << "Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] " << " Destructor called" << std::endl;
}