#include "ScalarConverter.hpp"

char ScalarConverter::_character;
int ScalarConverter::_integerNum;
float ScalarConverter::_floatNum;
double ScalarConverter::_doubleNum;
int	ScalarConverter::_infinitySign;
int ScalarConverter::_overflow;
int ScalarConverter::_characterFlg;
int ScalarConverter::_valueType;
std::string ScalarConverter::_value;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
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

void ScalarConverter::testPrintType()
{
	switch (_valueType)
	{
		case CHAR :
			std::cout << "type : " << "char" << std::endl << std::endl;
			break ;
		case INT :
			std::cout << "type : " << "int" << std::endl << std::endl;
			break ;
		case FLOAT :
			std::cout << "type : " << "float" << std::endl << std::endl;
			break ;
		case DOUBLE :
			std::cout << "type : " << "double" << std::endl << std::endl;
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
}

void ScalarConverter::printChar()
{
	if ( _characterFlg == NONDISPLAYABLE)
		std::cout << "char: " << "Non displayable" << std::endl;
	else if (_characterFlg == OVERFLOWCHAR || _valueType == NANDOUBLE || _valueType == NANFLAOT || _valueType == INFINITYFLOAT || _valueType == INFINITYDOUBLE || _overflow == OVERFLOWINT)
		std::cout << "char: " << "impossible" << std::endl;
	else
		std::cout << "char: '" << getChar() << "'" << std::endl;
}

void ScalarConverter::printInt()
{
	if (_overflow == INFINITYFLOAT || _overflow == INFINITYDOUBLE || _valueType == NANDOUBLE || _valueType == NANFLAOT || _valueType == INFINITYFLOAT || _valueType == INFINITYDOUBLE || _overflow == OVERFLOWINT)
		std::cout << "int: " << "impossible" << std::endl;
	else
		std::cout << "int: " << getInt() << std::endl;
}

void ScalarConverter::printFloat()
{
	if (_valueType == NANDOUBLE || _valueType == NANFLAOT)
		std::cout << "float: " << "nanf" << std::endl;
	else if (_valueType == INFINITYFLOAT || _valueType == INFINITYDOUBLE)
	{
		std::string signstr;
		if (_infinitySign == -1)
			signstr = "-";
		std::cout << "float: " << signstr << "inff" << std::endl;
	}
	else if (_overflow == OVERFLOWINT)
		std::cout << "float: " << "impossible" << std::endl;
	else
	{
		size_t printCnt;
		size_t dotPoint = _value.find('.');
		size_t isfloat = 0;
		if (_value.find('f') != std::string::npos)
			isfloat = 1;
		if (dotPoint == std::string::npos || _value.length() - isfloat - dotPoint == 1)
			printCnt = 1;
		else
			printCnt = static_cast<size_t>(_value.length() - isfloat - dotPoint - 1);
		std::cout << "float: " << std::fixed << std::setprecision(printCnt) <<  getFloat() << "f" << std::endl;
	}
}

void ScalarConverter::printDouble()
{
	if (_valueType == NANDOUBLE || _valueType == NANFLAOT)
		std::cout << "double: " << "nan" << std::endl;
	else if (_valueType == INFINITYFLOAT || _valueType == INFINITYDOUBLE)
	{
		std::string signstr;
		if (_infinitySign == -1)
			signstr = "-";
		std::cout << "double: " << signstr << "inf" << std::endl;
	}
	else if (_overflow == OVERFLOWINT)
		std::cout << "double: " << "impossible" << std::endl;
	else
		std::cout << "double: " << getDouble() << std::endl;
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
		_characterFlg = OVERFLOWCHAR;
}

void ScalarConverter::floatConvertToOther()
{
	_character = static_cast<char>(_floatNum);
	_integerNum = static_cast<int>(_floatNum);
	_doubleNum = static_cast<double>(_floatNum);
	if (std::isprint(_character) == 0)
		_characterFlg = NONDISPLAYABLE;
	if (!(_floatNum >= std::numeric_limits<char>::min() && _floatNum <= std::numeric_limits<char>::max()))
		_characterFlg = OVERFLOWCHAR;
	if (!(_floatNum >= std::numeric_limits<int>::min() && _floatNum <= std::numeric_limits<int>::max()))
	{
		_overflow = INFINITYFLOAT;
		if (_floatNum < std::numeric_limits<int>::min())
			_infinitySign = -1;
		else
			_infinitySign = 1;
	}
}

void ScalarConverter::doubleConvertToOther()
{
	_character = static_cast<char>(_doubleNum);
	_integerNum = static_cast<int>(_doubleNum);
	_floatNum = static_cast<float>(_doubleNum);
	if (std::isprint(_character) == 0)
		_characterFlg = NONDISPLAYABLE;
	if (!(_doubleNum >= std::numeric_limits<char>::min() && _doubleNum <= std::numeric_limits<char>::max()))
		_characterFlg = OVERFLOWCHAR;
	if (!(_doubleNum >= std::numeric_limits<int>::min() && _doubleNum <= std::numeric_limits<int>::max()))
	{
		_overflow = INFINITYDOUBLE;
		if (_doubleNum < std::numeric_limits<int>::min())
			_infinitySign = -1;
		else
			_infinitySign = 1;
	}
}

bool ScalarConverter::errorPrint(std::string str)
{
	std::cout << str << std::endl;
	return (false);
}

void ScalarConverter::typeSetChar()
{
	_valueType = CHAR;
	_character = *(_value.c_str());
}

void ScalarConverter::typeSetInt(double num)
{
	_valueType = INT;
	_integerNum = static_cast<int>(num);
	if (!(num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max()))
		_overflow = OVERFLOWINT;
}

void ScalarConverter::typeSetFloat(double num)
{
	if (!(num == num))
	{
		_valueType = NANFLAOT;
		_floatNum = static_cast<float>(num);
		_doubleNum = static_cast<double>(num);
		return ;
	}
	if (num == INFINITY || num == -INFINITY)
	{
		_valueType = INFINITYFLOAT;
		_floatNum = static_cast<float>(num);
		_doubleNum = static_cast<double>(num);
		if (num == INFINITY)
			_infinitySign = 1;
		else
			_infinitySign = -1;
		return ;
	}
	_valueType = FLOAT;
	_floatNum = static_cast<float>(num);
}

void ScalarConverter::typeSetDouble(double num)
{
	if (!(num == num))
	{
		_valueType = NANDOUBLE;
		_floatNum = static_cast<float>(num);
		_doubleNum = static_cast<double>(num);
		return ;
	}
	if (num == INFINITY || num == -INFINITY)
	{
		_valueType = INFINITYDOUBLE;
		_floatNum = static_cast<float>(num);
		_doubleNum = static_cast<double>(num);
		if (num == INFINITY)
			_infinitySign = 1;
		else
			_infinitySign = -1;
		return ;
	}
	if (_value.find('.') != std::string::npos)
	{
		_valueType = DOUBLE;
		_doubleNum = static_cast<double>(num);;
		return ;
	}
}

bool ScalarConverter::myStrIsspace(std::string str)
{
	int length = static_cast<int>(str.length());

	for (int i = 0; i < length; i++)
	{
		if (std::isspace(str.at(i)) != 0)
			return (false);	
	}
	return (true);
}

bool ScalarConverter::typeChk()
{
	int	length = static_cast<int>(_value.length());
	if (length == 1 && !(_value.at(0) >= '0' && _value.at(0) <= '9'))
	{
		if (std::isprint(_value.at(0)) == 0)
			return (false);
		typeSetChar();
		return (true);
	}
	if (myStrIsspace(_value) == false)
		return (false);
	char *offset = NULL;
	double num = std::strtod(_value.c_str(), &offset);
	std::string cppOffset = offset;
	if (!(cppOffset.length() == 0 || (cppOffset.length() > 0 && std::strncmp(offset, "f\0", 2) == 0)))
		return (false);
	if ((cppOffset.length() > 0 && std::strncmp(offset, "f\0", 2) == 0))
		typeSetFloat(num);
	else if (!(num == num) || num == INFINITY || num == -INFINITY || _value.find('.') != std::string::npos)
		typeSetDouble(num);
	else
		typeSetInt(num);
	return (true);
}

void ScalarConverter::convert(std::string value)
{
	_value = value;
	if (typeChk() == false)
	{
		errorPrint("argv error");
		return ;
	}
	switch (_valueType)
	{
		case CHAR :
			charConvertToOther();
			break ;
		case INT :
			intConvertToOther();
			break ;
		case FLOAT :
			floatConvertToOther();
			break ;
		case DOUBLE :
			doubleConvertToOther();
			break ;
	}
	printChar();
	printInt();
	printFloat();
	printDouble();
}
