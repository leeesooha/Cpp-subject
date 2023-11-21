#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try {
        Bureaucrat person("romeo", 31);
        Form document("tax", 30, 10);
        person.signForm(document);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
