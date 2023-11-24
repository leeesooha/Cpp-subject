#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>

class PresidentialPardonForm : public AForm
{
    public :
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
        std::string getTarget() const;
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
        std::string _target;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& form);

#endif