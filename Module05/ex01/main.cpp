#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat person("romeo", 9);
        Form document("tax form", 10, 10);
        person.signForm(document);
        std::cout << document;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
