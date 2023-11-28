#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <limits>
#include <iomanip>

enum type {
    NONE = 0,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NANFLAOT,
    NANDOUBLE,
    INFINITYFLOAT,
    INFINITYDOUBLE,
    OVERFLOWINT,
    OVERFLOWCHAR,
    NONDISPLAYABLE
};

class ScalarConverter
{
    public :
        static char getChar();
        static int getInt();
        static float getFloat();
        static double getDouble();
        static void printAllValue(std::string value);
        static bool typeChk(std::string value);
        static bool myStrIsspace(std::string str);
        static void charConvertToOther();
        static void intConvertToOther();
        static void floatConvertToOther();
        static void doubleConvertToOther();
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter& other);
        virtual ~ScalarConverter();
        static char _character;
        static int _integerNum;
        static float _floatNum;
        static double _doubleNum;
        static int _valueType;
        static int _infinitySign;
        static int _overflow;
        static int _characterFlg;
};

#endif