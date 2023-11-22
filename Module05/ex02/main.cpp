#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try {
        Bureaucrat person("romeo", 151);
        ShrubberyCreationForm docTree("3tree");
        std::cout << person;
        std::cout << docTree;
        person.signForm(docTree);
        person.executeForm(docTree);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
