#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook {
	private :
		int current_list_contact;
		int number_of_contact;
		std::string print_form(std::string str);
	public :
		Contact contacts[8];

		PhoneBook() : current_list_contact(0), number_of_contact(0) {};
		~PhoneBook() {};
		void add();
		void search();
};

#endif


// std::string input_first_name, std::string input_last_name, std::string input_nickname, std::string input_phone_number, std::string input_darkest_secret