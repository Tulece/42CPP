#include <iostream>
#include "Span.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Provided test:" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Span sp_one(1);
	sp_one.addNumber(5);
	try
	{
		std::cout << sp_one.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught (shortestSpan with one number): " << e.what() << std::endl;
	}

	Span sp_large(10000);
	std::vector<int> numbers;
	srand(time(NULL));
	for (int i = 0; i < 10000; ++i)
	{
		numbers.push_back(rand());
	}
	try
	{
		sp_large.addNumber(numbers.begin(), numbers.end());
		std::cout << "Testing with 10,000 numbers:" << std::endl;
		std::cout << "Shortest span: " << sp_large.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp_large.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught during large test: " << e.what() << std::endl;
	}

	Span sp_range(10);
	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(3);
	lst.push_back(17);
	lst.push_back(9);
	lst.push_back(11);

	try
	{
		sp_range.addNumber(lst.begin(), lst.end());
		std::cout << "Testing addNumber with iterator range:" << std::endl;
		std::cout << sp_range.shortestSpan() << std::endl;
		std::cout << sp_range.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught during iterator range test: " << e.what() << std::endl;
	}

	return 0;
}
