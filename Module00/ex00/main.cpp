#include "megaphone.hpp"

int main(int argc, char **argv)
{
	MegaPhone mymegaphone;
	std::string messages = "";

	if (argc == 1) {
		mymegaphone.noise_shout("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		return (0);
	}
	else {
		for (int i = 1; i < argc; i++) {
			messages.append(argv[i]);
		}
		mymegaphone.shout(messages);
	}
	return (0);
}