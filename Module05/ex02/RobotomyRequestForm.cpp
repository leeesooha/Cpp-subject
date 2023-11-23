#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default_ShrubberyName", ROBOT_SIGNGRADE, ROBOT_EXECGRADE)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, ROBOT_SIGNGRADE, ROBOT_EXECGRADE)
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

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& person)
{
    out << person.getName() << ", " << "RobotomyRequestForm sign_grade " << person.getSignGrade() << ", " << "exec_grade " << person.getExecGrade() << ", signed " << std::boolalpha << person.getSigned() << "." << std::endl;
	return (out);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "drilling noises. . ." << std::endl;
	srand(static_cast<unsigned int>(time(NULL)));
	if (rand() % 2 == 0)
		std::cout << this->getName() << " robotomized Success!" << std::endl;
	else
		std::cout << this->getName() << " robotomized Fail!" << std::endl;
}