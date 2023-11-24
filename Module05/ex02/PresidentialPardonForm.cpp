#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential pardon", PARDON_SIGNGRADE, PARDON_EXECGRADE), _target("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential pardon", PARDON_SIGNGRADE, PARDON_EXECGRADE), _target(target)
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

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form)
{
    out << form.getName() << ", " \
	<< "PresidentialPardonForm sign_grade " << form.getSignGrade() << ", " \
	<< "exec_grade " << form.getExecGrade() \
	<< ", signed " << std::boolalpha << form.getSigned() \
	<< ", target " << form.getTarget() \
	<< "." << std::endl;
	return (out);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->getTarget() << " pardoned!" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}