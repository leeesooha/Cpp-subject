#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <iomanip>

enum bitcoinExchangeStatus {
    CSVFILEOPENERROR,
    CSVFILECONTENTERROR
};

class BitcoinExchange
{
    private :
        std::map<std::string, double> _exchangeRateBoard;
        bool openExchangeRate();
        bool readExchangeRatesFromFile();
        int _status;
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        virtual ~BitcoinExchange();
        void printExchangeRateBoard();
        void exchangeCoin(std::string filename);
};

#endif