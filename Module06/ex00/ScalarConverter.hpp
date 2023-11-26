#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
    public :
        static char getChar();
        static int getInt();
        static float getFloat();
        static double getDouble();
        static void printAllValue(std::string value);
        static bool typeChk(std::string value);
        static bool myStrIsprint(std::string str);
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter& operator=(const ScalarConverter& other);
        virtual ~ScalarConverter();
        static char _charater;
        static std::string _characterFlg;
        static int _integerNum;
        static std::string _integerFlg;
        static float _floatNum;
        static std::string _floatFlg;
        static double _doubleNum;
        static std::string _doubleFlg;
        static std::string _valueType;
};

#endif