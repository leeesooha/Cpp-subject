#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
    public :
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(const Form &other);
        Form& operator=(const Form& other);
        virtual ~Form();
        std::string getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        void beSinged(Bureaucrat &person);
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

std::ostream& operator<<(std::ostream& out, const Form& person);

#endif