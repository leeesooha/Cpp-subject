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
        Bureaucrat person("romeo", 20);
        ShrubberyCreationForm docTree("3tree");
        std::cout << person;
        std::cout << docTree;
        person.signForm(docTree);
        person.executeForm(docTree);
        std::cout << std::endl;

        RobotomyRequestForm robo("terminate");
        person.signForm(robo);
        person.executeForm(robo);
        std::cout << robo;
        std::cout << std::endl;

        PresidentialPardonForm pardon("pardonByZaphod");
        person.signForm(pardon);
        person.executeForm(pardon);
        std::cout << pardon;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
