#include "megaphone.hpp"

int main(int argc, char **argv)
{
	MegaPhone mymegaphone;

	if (argc == 1) {
		mymegaphone.noise_shout("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		return (0);
	}
	else {
		std::string messages;
		for (int i = 1; i < argc; i++) {
			messages.append(argv[i]);
			if (i != argc - 1)
				messages.append(" ");
		}
		mymegaphone.shout(messages);
	}
	return (0);
}