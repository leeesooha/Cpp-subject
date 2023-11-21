#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat person("romeo", 10);
        std::cout << person;
        person.decrementGrade();
        std::cout << person;
        person.incrementGrade();
        std::cout << person;
        person.incrementGrade();
        std::cout << person;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
