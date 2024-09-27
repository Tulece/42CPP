#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _exchangeRates(other._exchangeRates)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadExchangeRates(const std::string& filename)
{
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		throw FileOpenException();
	}
	std::string line;
	getline(infile, line);
	while (getline(infile, line))
	{
		std::stringstream ss(line);
		std::string date, rate_str;
		if (!getline(ss, date, ','))
			continue;
		if (!getline(ss, rate_str))
			continue;

		float rate = static_cast<float>(atof(rate_str.c_str()));
		_exchangeRates[date] = rate;
	}
}

float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);

	if (it != _exchangeRates.end() && it->first == date)
	{
		return it->second;
	}
	else if (it != _exchangeRates.begin())
	{
		--it;
		return it->second;
	}
	else
	{
		throw InvalidDateException();
	}
}


const char* BitcoinExchange::FileOpenException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return "Error: invalid date.";
}
