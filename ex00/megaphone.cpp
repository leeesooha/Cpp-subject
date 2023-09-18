#include "megaphone.hpp"

void MegaPhone::loud(int wordcount, char **words)
{
	std::string noise_loud = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (wordcount == 1) {
		std::cout << noise_loud << "\n";
		return ;
	}
	
}

void MegaPhone::noise_loud