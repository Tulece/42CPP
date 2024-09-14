#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <limits>
#include <cctype>
#include <exception>
#include <algorithm>
#include <sstream>

void ScalarConverter::convert(const std::string& literal)
{
	double dValue;
	bool isSpecial = false;
	char cValue = 0;
	std::string value = literal;

	std::string lowerLiteral = literal;
	std::transform(lowerLiteral.begin(), lowerLiteral.end(), lowerLiteral.begin(), ::tolower);

	if (literal.length() == 1 && !std::isdigit(literal[0]))
	{
		cValue = literal[0];
		dValue = static_cast<double>(cValue);
	}
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		cValue = literal[1];
		dValue = static_cast<double>(cValue);
	}
	else
	{
		if (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F')
		{
			value = literal.substr(0, literal.length() -1);
		}

		std::stringstream ss(value);
		ss >> dValue;
		if (ss.fail() || !ss.eof())
		{
			if (lowerLiteral == "nan" || lowerLiteral == "nanf")
			{
				dValue = std::numeric_limits<double>::quiet_NaN();
				isSpecial = true;
			}
			else if (lowerLiteral == "+inf" || lowerLiteral == "+inff" ||
					 lowerLiteral == "inf" || lowerLiteral == "inff")
			{
				dValue = std::numeric_limits<double>::infinity();
				isSpecial = true;
			}
			else if (lowerLiteral == "-inf" || lowerLiteral == "-inff")
			{
				dValue = -std::numeric_limits<double>::infinity();
				isSpecial = true;
			}
			else
			{
				std::cerr << "Invalid input" << std::endl;
				return;
			}
		}

	}

	std::cout << "char: ";
	if (isSpecial || dValue < std::numeric_limits<char>::min() || dValue > std::numeric_limits<char>::max() || std::isnan(dValue))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(dValue);
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (isSpecial || dValue < std::numeric_limits<int>::min() || dValue > std::numeric_limits<int>::max() || std::isnan(dValue))
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		int n = static_cast<int>(dValue);
		std::cout << n << std::endl;
	}

	std::cout << "float: ";
	float fValue = static_cast<float>(dValue);
	if (isSpecial)
		std::cout << fValue << "f" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << fValue << "f" << std::endl;

	std::cout << "double: ";
	if (isSpecial)
		std::cout << dValue << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << dValue << std::endl;
}
