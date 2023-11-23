#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

enum Grade{
    SHRUBBERY_SIGNGRADE = 145,
    SHRUBBERY_EXECGRADE = 137,
    ROBOT_SIGNGRADE = 72,
    ROBOT_EXECGRADE = 45,
    PARDON_SIGNGRADE = 25,
    PARDON_EXECGRADE = 5
};

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const;
        class GradeTooHighException : public std::exception
        {
            public :
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public : 
                virtual const char* what() const throw();
        };
    private :
        ShrubberyCreationForm();

};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& person);

#endif