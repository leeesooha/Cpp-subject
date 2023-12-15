#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

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
        bool error_print(std::string message);
        bool stringStreamEmptyCheck(std::istringstream &stream);
        bool isStrNumber(std::string str);
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