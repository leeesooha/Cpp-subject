#include "megaphone.hpp"

void MegaPhone::shout(std::string str)
{
	for (size_t i = 0; i < str.length(); i++) {
		if (std::islower(str.at(i))) {
			std::cout << static_cast<char>(std::toupper(str.at(i)));
		}
		else
			std::cout << static_cast<char>(str.at(i));
	}
	std::cout << std::endl;
}

void MegaPhone::noise_shout (std::string str)
{
	std::cout << str << std::endl;
}