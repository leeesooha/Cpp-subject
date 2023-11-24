#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class AForm;

enum formCount{
    FORM_TOTAL_COUNT = 3
};

class Intern
{
    public :
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern& other);
        virtual ~Intern();
        AForm *makeForm(std::string formName, std::string target);
};

#endif