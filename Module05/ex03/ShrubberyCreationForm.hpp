#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

enum ShrubberyGrade{
    SHRUBBERY_SIGNGRADE = 145,
    SHRUBBERY_EXECGRADE = 137
};

class ShrubberyCreationForm : public AForm
{
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        virtual void execute(Bureaucrat const & executor) const;
        std::string getTarget() const;
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
        std::string _target;

};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& form);

#endif