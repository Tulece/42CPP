#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <climits>
#include <cstdlib>

class RPN
{
public:
	RPN();

	RPN(const RPN& other);

	RPN& operator=(const RPN& other);

	~RPN();

	int evaluate(const std::string& expression);

	class InvalidExpressionException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	std::stack<int> _stack;

	bool isOperator(const std::string& token) const;

	void performOperation(const std::string& operatorToken);
};

#endif
