#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
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
        PresidentialPardonForm();

};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& person);

#endif