#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (1);
    }
    BitcoinExchange exchange;
    exchange.exchangeCoin(argv[1]);
    return (0);
}
