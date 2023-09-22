#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
	PhoneBook 	phonebook;
	Contact 	contact;
	std::string input;

	while (1) {
		std::cout << "PhoneBook> ";
		std::getline(std::cin, input);
		if (input.compare("ADD") == 0) {
			phonebook.add();
		}
		else if (input.compare("SEARCH") == 0) {
			phonebook.search();
		}
		else if (input.compare("EXIT") == 0) {
			break ;
		}
		else
			std::cout << "command not found." << std::endl;
	}
	return (0);
}