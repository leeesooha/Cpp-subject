#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>

class PhoneBook {
	public :
		void add(std::string input_first_name, std::string input_last_name, std::string input_nickname, std::string input_phone_number, std::string input_darkest_secret);
		void search(std::string str);
};

#endif