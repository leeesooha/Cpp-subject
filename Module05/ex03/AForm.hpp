#ifndef AAFORM_HPP
#define AAFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    public :
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(const AForm &other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getSigned() const;
        void setSigned(bool signFlag);
        void beSigned(Bureaucrat &person);
        virtual void execute(Bureaucrat const & executor) const = 0;
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
        const std::string _name;
        const int _signGrade;
        const int _execGrade;
        bool _signed;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif