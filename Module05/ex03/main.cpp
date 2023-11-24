#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

//Shrubbery 145, 137
//Robotomy  72, 45
//Presidential 25, 5

int main(void)
{
    try {
        Bureaucrat person("romeo", 1);
        std::cout << person;
        std::cout << std::endl;

        ShrubberyCreationForm shruForm("dfdf");
        person.signForm(shruForm);
        person.executeForm(shruForm);
        std::cout << shruForm;
        std::cout << std::endl;

        RobotomyRequestForm roboForm("Arnold");
        person.signForm(roboForm);
        person.executeForm(roboForm);
        std::cout << roboForm;
        std::cout << std::endl;

        PresidentialPardonForm pardonForm("Jane");
        person.signForm(pardonForm);
        person.executeForm(pardonForm);
        std::cout << pardonForm;
        std::cout << std::endl;

        Intern internPerson;
        AForm *forms;
        forms = internPerson.makeForm("robotomdy request", "jack");
        if (forms == NULL)
            std::exit (1);
        person.signForm(*forms);
        person.executeForm(*forms);
        delete forms;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
