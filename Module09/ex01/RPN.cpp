#include "RPN.hpp"

RPN::RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN()
{
}

void RPN::printStack()
{
	std::stack<int> stackTemp(this->_stackVar);

	std::cout << "---" << std::endl;
	while (stackTemp.empty() == false)
	{
		std::cout << " " << stackTemp.top() << std::endl;
		stackTemp.pop();
	}
	std::cout << "---" << std::endl << std::endl;
}

bool RPN::calculation(double a, double b, int oper, int *result)
{
	switch (oper)
	{
		case ADD:
			*result = a + b;
			break;
		case SUB:
			*result = a - b;
			break;
		case DIV:
		{
			if (b == 0)
				return (false);
			*result = a / b;
			break;
		}
		case MULTI:
			*result = a * b;
			break;
		default:
			break;
	}
	return (true);
}

void RPN::errorPrint(std::string message)
{
	std::cout << message << std::endl;
}

bool RPN::RPNFormCheck(std::string character)
{
	if (character.length() != 1)
		return (false);
	if (std::isdigit(character.at(0)) == 0 && !(character.at(0) == '+' || character.at(0) == '-' || character.at(0) == '/' || character.at(0) == '*'))
		return (false);
	return (true);
}

void RPN::run(std::string argv)
{
	int result = 0, a = 0, b = 0;
	std::istringstream iss(argv);
	std::string character;

	while (std::getline(iss, character, ' '))
	{
		if (RPNFormCheck(character) == false)
			return (errorPrint("Error"));
		if (std::isdigit(*(character.c_str())) == 0)
		{
			if (this->_stackVar.empty() == true)
				return (errorPrint("Error"));
			b = this->_stackVar.top();
			this->_stackVar.pop();
			if (this->_stackVar.empty() == true)
				return (errorPrint("Error"));
			a = this->_stackVar.top();
			this->_stackVar.pop();
			if (calculation(a, b, *(character.c_str()), &result) == false)
				return (errorPrint("Error"));
			this->_stackVar.push(result);
		}
		else
			this->_stackVar.push(*(character.c_str()) - '0');
	}
	if (this->_stackVar.size() != 1)
		return (errorPrint("Error"));
	else
		std::cout << this->_stackVar.top() << std::endl;
	return ;
}