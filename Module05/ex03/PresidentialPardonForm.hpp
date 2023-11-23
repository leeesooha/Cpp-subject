#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

enum PresidentialGrade{
    PARDON_SIGNGRADE = 25,
    PARDON_EXECGRADE = 5
};

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
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
        PresidentialPardonForm();
        std::string _target;

};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& person);

#endif