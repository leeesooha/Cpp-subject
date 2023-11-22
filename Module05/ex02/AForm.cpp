#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150), _signed(false)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

AForm::AForm(const AForm &other) : _name("Default"), _signGrade(150), _execGrade(150)
{
	*this = other;
}

AForm::~AForm()
{
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getSignGrade() const
{
	return (this->_signGrade);
}

int AForm::getExecGrade() const
{
	return (this->_execGrade);
}

std::ostream& operator<<(std::ostream& out, const AForm& person)
{
    out << person.getName() << ", " << "ShrubberyCreationForm sign_grade " << person.getSignGrade() << ", " << "exec_grade " << person.getExecGrade() << ", signed " << std::boolalpha << person.getSigned() << "." << std::endl;
	return (out);
}

void AForm::beSigned(Bureaucrat& person)
{
	if (person.getGrade() > this->getSignGrade())
	{
		this->_signed = false;
		throw Bureaucrat::GradeTooLowException();
	}
	this->_signed = true;
}

void AForm::setSigned(bool signFlag)
{
	this->_signed = signFlag;
}

bool AForm::getSigned() const
{
	return (this->_signed);
}