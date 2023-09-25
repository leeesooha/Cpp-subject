#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

class PhoneBook {
	private :
		int current_list_contact;
		int number_of_contact;
		std::string print_form(std::string str);
	public :
		Contact contacts[8];

		PhoneBook();
		~PhoneBook();
		void add();
		void search();
};

#endif