#include <iostream>
#include "iter.hpp"

void printInt(int const& x)
{
	std::cout << x << " ";
}

void printChar(char const& c)
{
	std::cout << c << " ";
}

template <typename T>
void increment(T& x)
{
	++x;
}

int main()
{
	int intArray[] = {0, 1, 2, 3, 4};
	const int constIntArray[] = {0, 1, 2, 3, 4};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	const char constCharArray[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Original int array: ";
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "Incremented int array: ";
	iter(intArray, 5, increment<int>);
	iter(intArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "Const int array: ";
	iter(constIntArray, 5, printInt);
	std::cout << std::endl;

	std::cout << "Original char array: ";
	iter(charArray, 5, printChar);
	std::cout << std::endl;

	std::cout << "Incremented char array: ";
	iter(charArray, 5, increment<char>);
	iter(charArray, 5, printChar);
	std::cout << std::endl;

	std::cout << "Const char array: ";
	iter(constCharArray, 5, printChar);
	std::cout << std::endl;

	// iter(constIntArray, 5, increment<int>); // Should not compile
	// iter(constCharArray, 5, increment<char>); // Should not compile

	return 0;
}
