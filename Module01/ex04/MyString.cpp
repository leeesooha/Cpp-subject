#include "MyString.hpp"

MyString::MyString(std::string &str) : mystr(&str)
{
}

MyString::~MyString()
{
}

void MyString::myReplace(size_t pos, size_t len, std::string &str)
{
	MyString::mystr->erase(pos, len);
	MyString::mystr->insert(pos, str);
}