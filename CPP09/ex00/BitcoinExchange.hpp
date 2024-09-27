#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> _exchangeRates;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadExchangeRates(const std::string& filename);
	float getExchangeRate(const std::string& date) const;

	class FileOpenException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class InvalidDateException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

#endif
