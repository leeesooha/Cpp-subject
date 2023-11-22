#include "Form.hpp"

Form::Form() : _name("Default"), _signGrade(150), _execGrade(150), _signed(false)
{
	std::cout << "[Form:" << this->_name << "] Default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	std::cout << "[Form:" << this->_name << "] Constructor called" << std::endl;
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	std::cout << "[Form:" << this->_name << "] Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::Form(const Form &other) : _name("Default"), _signGrade(150), _execGrade(150)
{
	std::cout << "[Form:" << this->_name << "] Copy constructor called" << std::endl;
	*this = other;
}

Form::~Form()
{
	std::cout << "[Form:" << this->_name << "] Destructor called" << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getSignGrade() const
{
	return (this->_signGrade);
}

int Form::getExecGrade() const
{
	return (this->_execGrade);
}

std::ostream& operator<<(std::ostream& out, const Form& person)
{
    out << person.getName() << ", " << "Form sign_grade " << person.getSignGrade() << ", " << "Form exec_grade " << person.getExecGrade() << "." << std::endl;
	return (out);
}

void Form::beSinged(Bureaucrat& person)
{
	if (person.getGrade() > this->getSignGrade())
	{
		this->_signed = false;
		throw Bureaucrat::GradeTooLowException();
	}
	this->_signed = true;
}
