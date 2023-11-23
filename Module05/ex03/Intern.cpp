#include "Intern.hpp"

Intern::Intern()
{
}

Intern& Intern::operator=(const Intern& other)
{
	if (this != &other)
		return (*this);
	return (*this);
}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[FORM_TOTAL_COUNT] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	size_t level_index = -1;
	AForm *form;

	form = NULL;
	for (size_t i = 0; i < FORM_TOTAL_COUNT; i++)
		if (forms[i] == formName)
			level_index = i;
	switch (level_index)
	{
		case 0 :
			form = new ShrubberyCreationForm(target);
			break ;
		case 1 :
			form = new RobotomyRequestForm(target);
			break ;
		case 2 :
			form = new PresidentialPardonForm(target);
			break ;
		default :
			std::cout << "The " << formName << " form does not exist." << std::endl;
			break ;
	}
	return (form);
}
