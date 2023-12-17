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

std::map<std::string, double>::iterator BitcoinExchange::findkey(std::string date)
{
	std::map<std::string, double>::iterator it = this->_exchangeRateBoard.find(date);
	if (it == this->_exchangeRateBoard.end())
	{
		it = this->_exchangeRateBoard.begin();
		if (date < it->first)
		{
			std::cout << "Error: bad input => " << date << std::endl;
			return (this->_exchangeRateBoard.end());
		}
		while (it != this->_exchangeRateBoard.end())
		{
			if (date < it->first)
				return (--it);
			it++;
		}
	}
	else
		return (it);
	it = this->_exchangeRateBoard.find(this->_exchangeRateBoard.rbegin()->first);
	return (it);
}

void BitcoinExchange::stringStreamChange(std::istringstream &stream, std::string str)
{
	stream.clear();
	stream.str(str);
}

bool BitcoinExchange::stringStreamEmptyCheck(std::istringstream &stream)
{
	std::string str;

	stream >> str;
	if (str.size() == 0)
		return (true);
	return (false);
}

bool BitcoinExchange::isStrSingNumber(std::string str)
{
	int dotFlag = 0;

	if (str.length() == 0)
		return (false);
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (i == 0 && (str.at(i) == '-' || str.at(i) == '+'))
		{
			if (str.length() == 1)
				return (false);
		}
		else if (str.at(i) == '.')
		{
			dotFlag++;
			if (dotFlag > 1)
				return (false);
		}
		else if (i > 0 && (str.at(i) == '-' || str.at(i) == '+'))
			return (false);
		else if (std::isdigit(str.at(i)) == 0)
			return (false);
	}
	return (true);
}

bool BitcoinExchange::dateCheck(double year, double month, double day)
{
	if (!(month <= 12 && month >= 1) || day < 1)
		return (false);
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (day < 1 || day > 31)
			return (false);
	if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day < 1 || day > 30)
			return (false);
	if (month == 2)
	{
		if (static_cast<int>(year) % 4 == 0)
		{
			if (static_cast<int>(year) % 100 == 0 && static_cast<int>(year) % 400 == 0)
			{
				if (day > 29)
					return (false);
			}
			else if (static_cast<int>(year) % 100 == 0)
			{
				if (day > 28)
					return (false);
			}
			else
			{
				if (day > 29)
					return (false);
			}
		}
		else
		{
			if (day > 28)
				return (false);
		}
	}
	return (true);
}

bool BitcoinExchange::StrNumberSize(std::string str, size_t size)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit(str.at(i)) == 0)
			return (false);
	}
	if (str.length() != size)
		return (false);
	return (true);
}

bool BitcoinExchange::lineFormatCheck(std::string line)
{
	std::istringstream strStreamLine(line);
	double year, month, day, count;
	std::string year_str, month_str, day_str, delimeter_str, count_str;

	std::getline(strStreamLine, year_str, '-');
	std::getline(strStreamLine, month_str, '-');
	std::getline(strStreamLine, day_str, ' ');
	std::getline(strStreamLine, delimeter_str, ' ');
	std::getline(strStreamLine, count_str);

	if (StrNumberSize(year_str, 4) == false || StrNumberSize(month_str, 2) == false || StrNumberSize(day_str, 2) == false \
		|| isStrSingNumber(count_str) == false)
		return (false);
	stringStreamChange(strStreamLine, year_str);
	strStreamLine >> year;
	if (stringStreamEmptyCheck(strStreamLine) == false)
		return (false);
	stringStreamChange(strStreamLine, month_str);
	strStreamLine >> month;
	if (stringStreamEmptyCheck(strStreamLine) == false)
		return (false);
	if ((std::strchr(day_str.c_str(), '-') != 0) || std::strchr(day_str.c_str(), '+') != 0)
		return (false);
	stringStreamChange(strStreamLine, day_str);
	strStreamLine >> day;
	if (stringStreamEmptyCheck(strStreamLine) == false)
		return (false);
	stringStreamChange(strStreamLine, count_str);
	strStreamLine >> count;
	if (stringStreamEmptyCheck(strStreamLine) == false)
		return (false);
	std::string date = year_str + "-" + month_str + "-" + day_str;
	if (date < this->_exchangeRateBoard.begin()->first || date > "2099-12-31")
		return (false);
	if (dateCheck(year, month, day) == false)
		return (false);
	return (true);
}

bool BitcoinExchange::error_print(std::string message, bool returnValue)
{
	std::cout << message << std::endl;
	return (returnValue);
}

void BitcoinExchange::error_print(std::string message)
{
	std::cout << message << std::endl;
}

void BitcoinExchange::exchangeCoin(std::string filename)
{
	std::istringstream strStreamLine;
	std::ifstream inputFile(filename.c_str());
	std::string line, date, count_str;
	std::map<std::string, double>::iterator it;
	double count;

	if (inputFile.is_open() == false)
		return (error_print("Error: could not open file."));
	std::getline(inputFile, line);
	if (line != "date | value")
		return (error_print("File Error"));
	while (std::getline(inputFile, line))
	{
		if (lineFormatCheck(line) == false)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		stringStreamChange(strStreamLine, line);
		std::getline(strStreamLine, date, '|');
		date.resize(10);
		std::getline(strStreamLine, count_str);
		stringStreamChange(strStreamLine, count_str);
		strStreamLine >> count;
		it = findkey(date);
		if (count > 1000 || count < 0)
		{
			if (count > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (it != this->_exchangeRateBoard.end())
			std::cout << date << " => " << count << " = " << it->second * count << std::endl;
	}
}

//getline은 stream에 있는 데이터를 문자열로만 받을 수 있어서 istringstream을 사용함. istringstream은 데이터를 자료형에 맞게 반환해줌. 그럼 istring으로 date도 받아와서 코드가 일관성을 가지면 좋은거 아니냐?? 아니다. istringstream은 공백,개행기준으로 데이터를 구분한다. 원하는 문자(여기선 ',')를 delimiter로 정할수 있는 getline이 필요하다.
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
		strStreamLine >> rate;
		this->_exchangeRateBoard[date] = rate;
	}
	return (true);
}

bool BitcoinExchange::readExchangeRatesFromFile()
{
	if (openExchangeRate() == false)
		return (false);
	return (true);
}