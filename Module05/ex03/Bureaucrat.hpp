#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>
#include <exception>

enum GradeRange{
    GRADE_MIN = 1,
    GRADE_MAX = 150
};

class AForm;

class Bureaucrat
{
    public :
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &document);
        void executeForm(AForm const & Aform);
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
        int _grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& person);

#endif
