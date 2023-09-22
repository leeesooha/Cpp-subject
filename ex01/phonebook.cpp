#include <iostream>
#include <iomanip>
#include "phonebook.hpp"
#include "contact.hpp"

std::string PhoneBook::print_form(std::string str) {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void PhoneBook::add() {
	std::string input[5];
	std::string display_str[5] = {"enter your firstname.", "enter your lastname.", "enter your nickname.", "enter your phone number.", "enter your darkest secret."};
	Contact new_contact;

	for (int i = 0; i < 5; i++) {
		std::cout << display_str[i] << std::endl;
		std::cout << "> ";
		std::getline(std::cin, input[i]);
		if (input[i].length() <= 0) {
			i--;
		} 
		else {
			for (int j = 0; j < static_cast<int>(input[i].length()); j++) {
				if (std::isspace(static_cast<char>(input[i][j])) == 0)
					break ;
				if (j == static_cast<int>(input[i].length()) - 1) {
					i--;
					break ;
				}
			}
		}
	}
	new_contact.setcontact(input[0], input[1], input[2], input[3], input[4]);
	if (PhoneBook::current_list_contact > 7)
		PhoneBook::current_list_contact = 0;
	PhoneBook::contacts[current_list_contact] = new_contact;
	PhoneBook::current_list_contact += 1;
	if (number_of_contact < 8)
		PhoneBook::number_of_contact += 1;
}

void PhoneBook::search() {
	std::string display_str = "enter the contact list number.";
	std::string input;
	int			search_index = 0;

	std::cout << display_str << "(range is 0 to 7)" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, input);
	search_index = std::atoi(input.c_str());
	if (search_index < 0 || search_index > 7) {
		std::cout << "The input value is incorrect." << std::endl;
		return ;
	}
	if (search_index >= PhoneBook::number_of_contact) {
		std::cout << "contact[" << search_index << "] does not exist." << std::endl;
		return ;
	}
	std::cout << "|" << std::setw(10) << print_form(input);
	std::cout << "|" << std::setw(10) << print_form(PhoneBook::contacts[search_index].get_firstname());
	std::cout << "|" << std::setw(10) << print_form(PhoneBook::contacts[search_index].get_last_name());
	std::cout << "|" << std::setw(10) << print_form(PhoneBook::contacts[search_index].get_nickname()) << "|" << std::endl;
}
