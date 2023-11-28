#include "ScalarConverter.hpp"

char ScalarConverter::_character;
int ScalarConverter::_integerNum;
float ScalarConverter::_floatNum;
double ScalarConverter::_doubleNum;
int	ScalarConverter::_infinitySign;
int ScalarConverter::_overflow;
int ScalarConverter::_characterFlg;
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
	return (_character);
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
	_integerNum = static_cast<int>(_character);
	_floatNum = static_cast<float>(_character);
	_doubleNum = static_cast<double>(_character);
}

void ScalarConverter::intConvertToOther()
{
	_character = static_cast<char>(_integerNum);
	_floatNum = static_cast<float>(_integerNum);
	_doubleNum = static_cast<double>(_integerNum);
	if (std::isprint(_character) == 0)
		_characterFlg = NONDISPLAYABLE;
	if (!(_integerNum >= std::numeric_limits<char>::min() && _integerNum <= std::numeric_limits<char>::max()))
		_characterFlg = NONDISPLAYABLE;
}

void ScalarConverter::floatConvertToOther()
{
	_character = static_cast<char>(_floatNum);
	_integerNum = static_cast<int>(_floatNum);
	_doubleNum = static_cast<double>(_floatNum);
	if (std::isprint(_character) == 0)
		_characterFlg = NONDISPLAYABLE;
}

void ScalarConverter::doubleConvertToOther()
{
	_character = static_cast<char>(_doubleNum);
	_integerNum = static_cast<int>(_doubleNum);
	_floatNum = static_cast<float>(_doubleNum);
	if (std::isprint(_character) == 0)
		_characterFlg = NONDISPLAYABLE;
}

bool ScalarConverter::typeChk(std::string value)
{
	int	length = value.length();
	if (length == 1 && !(value.at(0) >= '0' && value.at(0) <= '9'))
	{
		if (std::isprint(value.at(0)) == 0)
			return (false);
		_valueType = CHAR;
		_character = *(value.c_str());
		return (true);
	}
	if (myStrIsspace(value) == false)
		return (false);
	char *offset = NULL;
	double num = std::strtod(value.c_str(), &offset);
	std::string cppOffset = offset;
	if (!(cppOffset.length() == 0 || (cppOffset.length() > 0 && std::strncmp(offset, "f\0", 2) == 0)))
		return (false);
	if ((cppOffset.length() > 0 && std::strncmp(offset, "f\0", 2) == 0))
	{
		if (!(num == num))
		{
			_valueType = NANFLAOT;
			_floatNum = num;
			_doubleNum = num;
			return (true);
		}
		if (num == INFINITY || num == -INFINITY)
		{
			_valueType = INFINITYFLOAT;
			_floatNum = num;
			_doubleNum = num;
			if (num == INFINITY)
				_infinitySign = 1;
			else
				_infinitySign = -1;
			return (true);
		}
		_valueType = FLOAT;
		_floatNum = static_cast<float>(num);
		return (true);
	}
	if (!(num == num))
	{
		_valueType = NANDOUBLE;
		_floatNum = num;
		_doubleNum = num;
		return (true);
	}
	if (num == INFINITY || num == -INFINITY)
	{
		_valueType = INFINITYDOUBLE;
		_floatNum = num;
		_doubleNum = num;
		if (num == INFINITY)
			_infinitySign = 1;
		else
			_infinitySign = -1;
		return (true);
	}
	if (value.find('.') != std::string::npos)
	{
		_valueType = DOUBLE;
		_doubleNum = num;
		return (true);
	}
	_valueType = INT;
	_integerNum = static_cast<int>(num);
	if (!(num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max()))
		_overflow = OVERFLOWINT;
	return (true);
}

void ScalarConverter::printAllValue(std::string value)
{
	if (typeChk(value) == false)
	{
		std::cout << "argv Error" << std::endl;
		return ;
	}
	switch (_valueType)
	{
		case CHAR :
			std::cout << "type : " << "char" << std::endl << std::endl;
			charConvertToOther();
			break ;
		case INT :
			std::cout << "type : " << "int" << std::endl << std::endl;
			intConvertToOther();
			break ;
		case FLOAT :
			std::cout << "type : " << "float" << std::endl << std::endl;
			floatConvertToOther();
			break ;
		case DOUBLE :
			std::cout << "type : " << "double" << std::endl << std::endl;
			doubleConvertToOther();
			break ;
		case NANDOUBLE :
			std::cout << "type : " << "nan" << std::endl << std::endl;
			break ;
		case NANFLAOT :
			std::cout << "type : " << "nanf" << std::endl << std::endl;
			break ;
		case INFINITYFLOAT :
			std::cout << "type : " << "inff" << std::endl << std::endl;
			break ;
		case INFINITYDOUBLE :
			std::cout << "type : " << "inf" << std::endl << std::endl;
			break ;
	}
	if (_valueType == NANDOUBLE || _valueType == NANFLAOT)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "nanf" << std::endl;
		std::cout << "double: " << "nan" << std::endl;
		return ;
	}
	if (_valueType == INFINITYFLOAT || _valueType == INFINITYDOUBLE)
	{
		std::string signstr;
		if (_infinitySign == -1)
			signstr = "-";
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << signstr << "inff" << std::endl;
		std::cout << "double: " << signstr << "inf" << std::endl;
		return ;
	}
	if (_overflow == OVERFLOWINT)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible" << std::endl;
		return ;
	}
	if ( _characterFlg == NONDISPLAYABLE)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << getChar() << "'" << std::endl;
	std::cout << "int: " << getInt() << std::endl;

	size_t printCnt;
	size_t dotPoint = value.find('.');
	size_t isfloat = 0;
	if (value.find('f') != std::string::npos)
		isfloat = 1;
	if (dotPoint == std::string::npos || value.length() - isfloat - dotPoint == 1)
		printCnt = 1;
	else
		printCnt = value.length() - isfloat - dotPoint - 1;
	std::cout << "float: " << std::fixed << std::setprecision(printCnt) <<  getFloat() << "f" << std::endl;
	std::cout << "double: " << getDouble() << std::endl;
}