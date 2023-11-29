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
        static void convert(std::string value);
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        static char getChar();
        static int getInt();
        static float getFloat();
        static double getDouble();
        static bool typeChk();
        static bool myStrIsspace(std::string str);
        static void charConvertToOther();
        static void intConvertToOther();
        static void floatConvertToOther();
        static void doubleConvertToOther();
        static void printChar();
        static void printInt();
        static void printFloat();
        static void printDouble();
        static void testPrintType();
        static void typeSetChar();
        static void typeSetInt(double num);
        static void typeSetFloat(double num);
        static void typeSetDouble(double num);
        static bool errorPrint(std::string str);
        static char _character;
        static int _integerNum;
        static float _floatNum;
        static double _doubleNum;
        static int _valueType;
        static int _infinitySign;
        static int _overflow;
        static int _characterFlg;
        static std::string _value;
};

#endif