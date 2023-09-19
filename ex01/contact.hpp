#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    Contact(std::string input_first_name, std::string input_last_name, std::string input_nickname, std::string input_phone_number, std::string input_darkest_secret)
        : first_name(input_first_name), last_name(input_last_name), nickname(input_nickname), phone_number(input_phone_number), darkest_secret(input_darkest_secret) {
    }

// private:
    // std::string first_name;
    // std::string last_name;
    // std::string nickname;
    // std::string phone_number;
};

#endif