#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>
#include <string>
#include <iostream>
#include <exception>

enum RobotomyGrade{
    ROBOT_SIGNGRADE = 72,
    ROBOT_EXECGRADE = 45
};

class RobotomyRequestForm : public AForm
{
    public :
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
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

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& form);

#endif