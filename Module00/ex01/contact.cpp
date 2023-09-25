#include "contact.hpp"

Contact::Contact() : first_name(""),
                    last_name(""),
                    nickname(""),
                    phone_number(""),
                    darkest_secret("")
{
}
Contact::~Contact()
{
}

void Contact::setcontact(std::string pb_first_name,
						std::string pb_last_name,
						std::string pb_nickname,
						std::string pb_phone_number,
						std::string pb_darkest_secret)
{
	Contact::first_name = pb_first_name;
	Contact::last_name = pb_last_name;
	Contact::nickname = pb_nickname;
	Contact::phone_number = pb_phone_number;
	Contact::darkest_secret = pb_darkest_secret;
}

std::string Contact::get_firstname ()
{
	return (Contact::first_name);
}

std::string Contact::get_last_name ()
{
	return (Contact::last_name);
}

std::string Contact::get_nickname ()
{
	return (Contact::nickname);
}

std::string Contact::get_phone_number ()
{
	return (Contact::phone_number);
}

std::string Contact::get_darkest_secret ()
{
	return (Contact::darkest_secret);
}