#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <cctype>

bool isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (year < 2009 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	int daysInMonth[] = { 31, 28, 31, 30, 31, 30,
						  31, 31, 30, 31, 30, 31 };

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		daysInMonth[1] = 29;
	}

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}


bool isValidValue(const std::string& value_str)
{
	char* endptr;
	double value = strtod(value_str.c_str(), &endptr);
	if (*endptr != '\0' && !isspace(*endptr))
		return false;
	if (value < 0 || value > 1000)
		return false;
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btcExchange;
	try
	{
		btcExchange.loadExchangeRates("data.csv");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	std::ifstream infile(argv[1]);
	if (!infile)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string line;
	getline(infile, line);

	while (getline(infile, line))
	{
		std::stringstream ss(line);
		std::string date, value_str;

		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		date = line.substr(0, pos);
		value_str = line.substr(pos + 1);

		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		value_str.erase(0, value_str.find_first_not_of(" \t"));
		value_str.erase(value_str.find_last_not_of(" \t") + 1);

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidValue(value_str))
		{
			double value = atof(value_str.c_str());
			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		double value = atof(value_str.c_str());
		try
		{
			float rate = btcExchange.getExchangeRate(date);
			double result = value * rate;
			std::cout << date << " => " << value_str << " = " << result << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}

	return 0;
}
