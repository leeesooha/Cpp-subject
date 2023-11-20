//멤버변수 name이  const임, 복사생성어케 할 건지??
//잘못된 grade로 Bureaucrat 클래스를 인트턴스화 시도시 exception 던져야함.
//exception은 멤버함수로 던져야 하는듯?? Buereaucrat::GradeTooHighException or Bureaucrat::GradeTooLowException
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
    public :
        Bureaucrat();
        Bureaucrat(std::string name);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat& operator=(const Bureaucrat& other);
        virtual ~Bureaucrat();
    private :
        const std::string _name;
        int grade;
};

#endif