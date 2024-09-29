#include "RPN.hpp"
#include <climits>

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	this->_stack = other._stack;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::performOperation(const std::string& operatorToken)
{
	if (_stack.size() < 2)
		throw InvalidExpressionException();

	int rhs = _stack.top();
	_stack.pop();
	int lhs = _stack.top();
	_stack.pop();

	long result = 0;

	if (operatorToken == "+")
	{
		result = static_cast<long>(lhs) + static_cast<long>(rhs);
		if (result > INT_MAX || result < INT_MIN)
			throw InvalidExpressionException();
	}
	else if (operatorToken == "-")
	{
		result = static_cast<long>(lhs) - static_cast<long>(rhs);
		if (result > INT_MAX || result < INT_MIN)
			throw InvalidExpressionException();
	}
	else if (operatorToken == "*")
	{
		result = static_cast<long>(lhs) * static_cast<long>(rhs);
		if (result > INT_MAX || result < INT_MIN)
			throw InvalidExpressionException();
	}
	else if (operatorToken == "/")
	{
		if (rhs == 0)
			throw InvalidExpressionException();
		if (lhs == INT_MIN && rhs == -1)
			throw InvalidExpressionException();
		result = lhs / rhs;
	}
	else
	{
		throw InvalidExpressionException();
	}

	_stack.push(static_cast<int>(result));
}

int RPN::evaluate(const std::string& expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isOperator(token))
		{
			performOperation(token);
		}
		else
		{
			char* endptr;
			long num = std::strtol(token.c_str(), &endptr, 10);
			if (*endptr == '\0')
			{
				if (num > INT_MAX || num < INT_MIN)
					throw InvalidExpressionException();
				_stack.push(static_cast<int>(num));
			}
			else
			{
				throw InvalidExpressionException();
			}
		}
	}

	if (_stack.size() != 1)
		throw InvalidExpressionException();

	return _stack.top();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
	return "Error";
}
