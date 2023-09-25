#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>

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