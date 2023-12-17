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
        std::map<std::string, double>::iterator findkey(std::string date);
        bool lineFormatCheck(std::string line);
        void stringStreamChange(std::istringstream &stream, std::string str);
        int _status;
        bool error_print(std::string message, bool returnValue);
        void error_print(std::string message);
        bool stringStreamEmptyCheck(std::istringstream &stream);
        bool isStrSingNumber(std::string str);
        bool StrNumberSize(std::string str, size_t size);
        bool dateCheck(double year, double month, double day);
    public :
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        virtual ~BitcoinExchange();
        void printExchangeRateBoard();
        void exchangeCoin(std::string filename);
};

#endif