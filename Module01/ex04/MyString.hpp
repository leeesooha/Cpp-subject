#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <string>
#include <iostream>
#include <fstream>

class MyString
{
	public :
		MyString(std::string &str);
		~MyString();
		void myReplace(size_t pos, size_t len, std::string& str);
	private :
		std::string *_myStr;
};

#endif