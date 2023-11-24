#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

//Shrubbery 145, 137
//Robotomy  72, 45
//Presidential 25, 5

int main(void)
{
    try {
        Bureaucrat person("romeo", 10);
        ShrubberyCreationForm shruForm("home");

        for (int i = 0; i < 5; i++)
            person.incrementGrade();
        std::cout << person;
        std::cout << shruForm;
        person.signForm(shruForm);
        person.executeForm(shruForm);
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
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
