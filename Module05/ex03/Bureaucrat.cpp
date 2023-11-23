#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < GRADE_MIN)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > GRADE_MAX)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
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
	if (this->_grade - 1 < GRADE_MIN)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > GRADE_MAX)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& person)
{
    out << person.getName() << ", " << "bureaucrat grade " << person.getGrade() << "." << std::endl;
	return (out);
}

void Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't executed " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &document)
{
	try {
		document.beSigned(*this);
		std::cout << this->getName() << " signed " << document.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign " << document.getName() << " because " << e.what() << std::endl;
	}
}