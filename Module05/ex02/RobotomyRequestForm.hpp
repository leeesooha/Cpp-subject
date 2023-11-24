#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
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

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif