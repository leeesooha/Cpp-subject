#include "MyString.hpp"

MyString::MyString(std::string &str) : _myStr(&str)
{
}

MyString::~MyString()
{
}

void MyString::myReplace(size_t pos, size_t len, std::string &str)
{
	MyString::_myStr->erase(pos, len);
	MyString::_myStr->insert(pos, str);
}