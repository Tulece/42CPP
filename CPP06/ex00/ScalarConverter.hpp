#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
private:
	ScalarConverter();

public:
	static void convert(const std::string& literal);
};

#endif
