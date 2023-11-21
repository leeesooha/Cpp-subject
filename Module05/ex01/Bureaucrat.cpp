#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "[Bureaucrat:" << this->_name << "] Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "[Bureaucrat:" << this->_name << "] Constructor called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "[Bureaucrat:" << this->_name << "] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	std::cout << "[Bureaucrat:" << this->_name << "] Copy constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat:" << this->_name << "] Destructor called" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& person)
{
    out << person.getName() << ", " << "bureaucrat grade " << person.getGrade() << "." << std::endl;
	return (out);
}

void Bureaucrat::signForm(Form &document)
{
	try {
		document.beSinged(*this);
		std::cout << this->getName() << " signed " << document.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << document.getName() << " because " << e.what() << std::endl;
	}
}