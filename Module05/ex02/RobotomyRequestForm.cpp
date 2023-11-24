#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy request", ROBOT_SIGNGRADE, ROBOT_EXECGRADE), _target("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", ROBOT_SIGNGRADE, ROBOT_EXECGRADE), _target(target)
{
	if (AForm::getSignGrade() < GRADE_MIN || AForm::getExecGrade() < GRADE_MIN)
		throw RobotomyRequestForm::GradeTooHighException();
	else if (AForm::getSignGrade() > GRADE_MAX || AForm::getExecGrade() > GRADE_MAX)
		throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		this->setSigned(other.getSigned());
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form)
{
    out << form.getName() << ", " \
	<< "RobotomyRequestForm sign_grade " << form.getSignGrade() << ", " \
	<< "exec_grade " << form.getExecGrade() \
	<< ", signed " << std::boolalpha << form.getSigned() \
	<< ", target " << form.getTarget() \
	<< "." << std::endl;
	return (out);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "drilling noises. . ." << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " robotomized Success!" << std::endl;
	else
		std::cout << this->getTarget() << " robotomized Fail!" << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}