#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "argv Error" << std::endl;
        return (1);
    }
    ScalarConverter::printAllValue(argv[1]);
    return (0);
}
