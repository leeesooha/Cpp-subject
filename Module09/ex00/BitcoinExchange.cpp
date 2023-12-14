#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	if (readExchangeRatesFromFile() == false)
	{
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::printExchangeRateBoard()
{
	for (std::map<std::string, double>::iterator it = this->_exchangeRateBoard.begin(); it != this->_exchangeRateBoard.end(); it++)
		std::cout << it->first << "," << std::setprecision(10) << it->second << std::endl;
}

bool BitcoinExchange::readExchangeRatesFromFile()
{
	if (openExchangeRate() == false)
		return (false);
	return (true);
}

bool BitcoinExchange::openExchangeRate()
{
	std::fstream ExchangeRateFile("./data.csv");

	if (ExchangeRateFile.is_open() == false)
	{
		this->_status = CSVFILEOPENERROR;
		return (false);
	}

	std::string line;
	std::getline(ExchangeRateFile, line);
	if (line != "date,exchange_rate")
	{
		this->_status = CSVFILECONTENTERROR;
		return (false);
	}
	std::istringstream strStreamLine;
	std::string date, temp;
	double rate;
	while (std::getline(ExchangeRateFile, line))
	{
		strStreamLine.clear();
		strStreamLine.str(line);

		std::getline(strStreamLine, date, ',');
		strStreamLine >> rate;		//getline은 stream에 있는 데이터를 문자열로만 받을 수 있어서 istringstream을 사용함. istringstream은 데이터를 자료형에 맞게 반환해줌. 그럼 istring으로 date도 받아와서 코드가 일관성을 가지면 좋은거 아니냐?? 아니다. istringstream은 공백,개행기준으로 데이터를 구분한다. 원하는 문자(여기선 ',')를 delimiter로 정할수 있는 getline이 필요하다.
		this->_exchangeRateBoard[date] = rate;
	}
	return (true);
}

void BitcoinExchange::exchangeCoin(std::string filename)
{
	std::fstream inputFile(filename);
	std::string line;

	if (inputFile.is_open() == false)
		return ;
	std::getline(inputFile, line);
	if (line != "date | value")
		return ;
	std::istringstream strStreamLine;
	std::string date;
	double count;
	while (std::getline(inputFile, line))
	{
		strStreamLine.clear();
		strStreamLine.str(line);
		std::getline(strStreamLine, date, '|');
		strStreamLine >> count;
		std::cout << date << "| " << count << std::endl;
	}
}