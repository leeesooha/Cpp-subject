#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <iomanip>
#include <fstream>

enum operatorFlag {
    ADD = '+',
    SUB = '-',
    DIV = '/',
    MULTI = '*'
};

class RPN
{
    private :
        std::stack<int> _stackVar;
        bool RPNFormCheck(std::string character);
        void errorPrint(std::string message);
        bool calculation(double a, double b, int oper, int *result);
        void printStack();
    public :
        RPN();
        RPN(const RPN &other);
        RPN& operator=(const RPN& other);
        virtual ~RPN();
        void run(std::string argv);
};

#endif