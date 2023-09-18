#include "megaphone.hpp"

int main(int argc, char **argv)
{
	MegaPhone mymegaphone;

	mymegaphone.loud(argc, argv);
	return (0);
}

//gpt 내용 확인

// #include <iostream>
// #include <string>
// #include <cctype>

// class Megaphone {
// public:
//     Megaphone(const std::string& input) {
//         this->input = input;
//     }

//     void shout() {
//         for (size_t i = 0; i < input.length(); ++i) {
//             if (islower(input[i])) {
//                 input[i] = toupper(input[i]);
//             }
//         }
//         std::cout << input << std::endl;
//     }

// private:
//     std::string input;
// };

// int main(int argc, char* argv[]) {
//     if (argc >= 2) {
//         std::string message;
//         for (int i = 1; i < argc; ++i) {
//             message += argv[i];
//             if (i < argc - 1) {
//                 message += " ";
//             }
//         }

//         Megaphone megaphone(message);
//         megaphone.shout();
//     } else {
//         std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
//     }

//     return 0;
// }
