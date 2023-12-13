#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>

class RPN
{
    public :
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        virtual ~RPN();
};


#endif