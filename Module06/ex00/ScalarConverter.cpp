#include "ScalarConverter.hpp"

char ScalarConverter::_charater;
int ScalarConverter::_integerNum;
float ScalarConverter::_floatNum;
double ScalarConverter::_doubleNum;
std::string ScalarConverter::_characterFlg = "NONPRINTABLE";
std::string ScalarConverter::_integerFlg = "NONPRINTABLE";
std::string ScalarConverter::_floatFlg = "NONPRINTABLE";
std::string ScalarConverter::_doubleFlg = "NONPRINTABLE";
int ScalarConverter::_valueType = NONE;

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
	if ()
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

bool ScalarConverter::myStrIsspace(std::string str)
{
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		if (std::isspace(str.at(i)) != 0)
			return (false);	
	}
	return (true);
}

void ScalarConverter::charConvertToOther()
{

}

bool ScalarConverter::typeChk(std::string value)
{
	int	length = value.length();
	if (length == 1 && !(value.at(0) >= '0' && value.at(0) <= '9'))
	{
		if (std::isprint(value.at(0)) == 0)
			return (false);
		_valueType = CHAR;
		return (true);
	}
	if (myStrIsspace(value) == false)
		return (false);
	char *offset = NULL;
	double num = std::strtod(value.c_str(), &offset);
	std::cout << "1: " << num << std::endl;
	std::string cppOffset = offset;
	if (!(cppOffset.length() == 0 || (cppOffset.length() > 0 && std::strncmp(offset, "f\0", 2) == 0)))
		return (false);
	if ((cppOffset.length() > 0 && std::strncmp(offset, "f\0", 2) == 0))
	{
		_valueType = FLOAT;
		return (true);
	}
	if (value.find('.') != std::string::npos)
	{
		_valueType = DOUBLE;
		return (true);
	}
	_valueType = INT;
	return (true);
	// if (num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max())
	// {
	// 	_valueType = "INT";
	// 	return (true);
	// }
	return (true);
}

void ScalarConverter::printAllValue(std::string value)
{
	if (typeChk(value) == false)
	{
		std::cout << "argv Error" << std::endl;
		return ;
	}
	// switch (expression)
	// {
	// case /* constant-expression */:
	// 	/* code */
	// 	break;
	
	// default:
	// 	break;
	// }
	std::cout << "type : " << _valueType << std::endl;
	std::cout << "char: '" << getChar() << "'" << std::endl;
	std::cout << "int: " << getInt() << std::endl;
	std::cout << "float: " << getFloat() << std::endl;
	std::cout << "double: " << getDouble() << std::endl;
}