#include "ScalarConverter.hpp"

char ScalarConverter::_charater;
int ScalarConverter::_integerNum;
float ScalarConverter::_floatNum;
double ScalarConverter::_doubleNum;
std::string ScalarConverter::_characterFlg = "NONPRINTABLE";
std::string ScalarConverter::_integerFlg = "NONPRINTABLE";
std::string ScalarConverter::_floatFlg = "NONPRINTABLE";
std::string ScalarConverter::_doubleFlg = "NONPRINTABLE";
std::string ScalarConverter::_valueType = "NONE";

ScalarConverter::ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	if (this != &other)
		;
	return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter::~ScalarConverter()
{
}

char ScalarConverter::getChar()
{
	return (_charater);
}

int ScalarConverter::getInt()
{
	return (_integerNum);
}

float ScalarConverter::getFloat()
{
	return (_floatNum);
}

double ScalarConverter::getDouble()
{
	return (_doubleNum);
}

bool ScalarConverter::myStrIsprint(std::string str)
{
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		if (std::isspace(str.at(i)) != 0)
			return (false);	
	}
	return (true);
}

bool ScalarConverter::typeChk(std::string value)
{
	int	length = value.length();
	if (length == 1 && !(value.at(0) >= '0' && value.at(0) <= '9'))
	{
		if (std::isprint(value.at(0)) == 0)
			return (false);
		_valueType = "CHAR";
		return (true);
	}
	if (myStrIsprint(value) == false)
		return (false);
	//char 타입 감지 완료, whitespace 문자 거르기 완료
	//int, float, double 감지할차례임.
	char *pos = NULL;
	double num = std::strtod(value.c_str(), &pos);
	std::cout << num << std::endl;
	return (true);
}

void ScalarConverter::printAllValue(std::string value)
{
	if (typeChk(value) == false)
	{
		std::cout << "argv Error" << std::endl;
		return ;
	}
	std::cout << "char: ";
	if (_characterFlg == "NONPRINTABLE")
		std::cout << "Non displayable";
	else
		std::cout << "'" << getChar() << "'";
	std::cout << std::endl;

	std::cout << "int: ";
	if (_integerFlg == "NONPRINTABLE")
		std::cout << "Non displayable";
	else
		std::cout << getFloat();
	std::cout << std::endl;

	std::cout << "float: ";
	if (_floatFlg == "NONPRINTABLE")
		std::cout << "Non displayable";
	else
		std::cout << getDouble();
	std::cout << std::endl;

	std::cout << "double: ";
	if (_doubleFlg == "NONPRINTABLE")
		std::cout << "Non displayable";
	else
		std::cout << getInt();
	std::cout << std::endl;
}