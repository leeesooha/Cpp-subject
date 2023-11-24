#include "Form.hpp"

Form::Form() : _name("Default_Form"), _signGrade(150), _execGrade(150), _signed(false)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (_signGrade < 1 || _execGrade < 1)
		throw Form::GradeTooHighException();
	else if (_signGrade > 150 || _execGrade > 150)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::Form(const Form &other) : _name("Default_Form"), _signGrade(150), _execGrade(150)
{
	*this = other;
}

Form::~Form()
{
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

bool Form::getSigned() const
{
	return (this->_signed);
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
    out << form.getName() << ", " \
	<< "Form sign_grade " << form.getSignGrade() << ", " \
	<< "exec_grade " << form.getExecGrade() \
	<< ", signed " << std::boolalpha << form.getSigned() \
	<< "." << std::endl;
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
