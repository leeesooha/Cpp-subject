#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", SHRUBBERY_SIGNGRADE, SHRUBBERY_EXECGRADE), _target("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", SHRUBBERY_SIGNGRADE, SHRUBBERY_EXECGRADE), _target(target)
{
	if (AForm::getSignGrade() < GRADE_MIN || AForm::getExecGrade() < GRADE_MIN)
		throw ShrubberyCreationForm::GradeTooHighException();
	else if (AForm::getSignGrade() > GRADE_MAX || AForm::getExecGrade() > GRADE_MAX)
		throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->setSigned(other.getSigned());
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("shrubbery creation", SHRUBBERY_SIGNGRADE, SHRUBBERY_EXECGRADE), _target("default_target")
{
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw()
{
	return ("grade too high");
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw()
{
	return ("grade too low");
}

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form)
{
    out << form.getName() << ", " \
	<< "ShrubberyCreationForm sign_grade " << form.getSignGrade() << ", " \
	<< "exec_grade " << form.getExecGrade() \
	<< ", signed " << std::boolalpha << form.getSigned() \
	<< ", target " << form.getTarget() \
	<< "." << std::endl;
	return (out);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false || executor.getGrade() > this->getExecGrade())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream outputFile((this->getTarget() + "_shrubbery").c_str());

	if (!outputFile.is_open())
	{
		std::cout << "fail file open" << std::endl;
		std::exit(1);
	}
	outputFile << "               ,@@@@@@@," << std::endl;
	outputFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	outputFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	outputFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	outputFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	outputFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	outputFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	outputFile << "       |o|        | |         | |" << std::endl;
	outputFile << "       |.|        | |         | |" << std::endl;
	outputFile << "_//_\\\\/ .\\_/\\_/__/  \\,_\\/__\\\\/.  \\_\\/\\/__/_";
	outputFile.close();
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}