#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
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
        RobotomyRequestForm();

};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& person);

#endif