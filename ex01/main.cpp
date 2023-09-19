#include "phonebook.hpp"
#include "contact.hpp"

int main(void)
{
	std::string str;
	PhoneBook phonebook;

	while (1) {
		std::getline(std::cin, str);
		if (str.compare("ADD") == 0) {
			phonebook.add;
		}
		else if (str.compare("SEARCH") == 0) {
			phonebook.search;
		}
		else if (str.compare("EXIT") == 0) {
			phonebook.exit;
			break ;
		}
		else
			std::cout << "command not found" << std::endl;
	}
	return (0);
}