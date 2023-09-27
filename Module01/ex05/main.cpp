#include "Harl.hpp"

int main(void)
{
	std::string debug_str = "DEBUG";
	std::string info_str = "INFO";
	std::string warning_str = "WARNING";
	std::string error_str = "ERROR";
	Harl harl;

	harl.complain(debug_str);
	harl.complain(info_str);
	harl.complain(warning_str);
	harl.complain(error_str);

	harl.complain(info_str);
	harl.complain(debug_str);
	harl.complain(error_str);
	harl.complain(warning_str);
	return (0);
}