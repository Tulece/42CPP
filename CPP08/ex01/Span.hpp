#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <iterator>

class Span
{
private:
	unsigned int        _N;
	std::vector<int>    _numbers;

public:
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	template <typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end)
	{
		unsigned int distance = static_cast<unsigned int>(std::distance(begin, end));
		if (_numbers.size() + distance > _N)
			throw StorageFullException();
		_numbers.insert(_numbers.end(), begin, end);
	}

	int shortestSpan() const;
	int longestSpan() const;

	class StorageFullException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Span storage is full.";
		}
	};

	class NoSpanFoundException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return "Not enough numbers stored to find a span.";
		}
	};
};

#endif
