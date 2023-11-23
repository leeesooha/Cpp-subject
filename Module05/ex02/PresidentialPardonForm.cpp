#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default_ShrubberyName", PARDON_SIGNGRADE, PARDON_EXECGRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, PARDON_SIGNGRADE, PARDON_EXECGRADE)
{
	if (AForm::getSignGrade() < GRADE_MIN || AForm::getExecGrade() < GRADE_MIN)
		throw PresidentialPardonForm::GradeTooHighException();
	else if (AForm::getSignGrade() > GRADE_MAX || AForm::getExecGrade() > GRADE_MAX)
		throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		this->setSigned(other.getSigned());
	}
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& person)
{
    out << person.getName() << ", " << "PresidentialPardonForm sign_grade " << person.getSignGrade() << ", " << "exec_grade " << person.getExecGrade() << ", signed " << std::boolalpha << person.getSigned() << "." << std::endl;
	return (out);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->getName() << " pardoned!" << std::endl;
}