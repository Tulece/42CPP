#include <iostream>
#include "Array.hpp"

int main()
{
	Array<int> emptyArray;
	std::cout << "Empty array size: " << emptyArray.size() << std::endl;

	Array<int> intArray(5);
	std::cout << "intArray size: " << intArray.size() << std::endl;
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = static_cast<int>(i * 10);
	}
	std::cout << "intArray elements: ";
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	Array<int> copyArray(intArray);
	std::cout << "copyArray elements after copying from intArray: ";
	for (size_t i = 0; i < copyArray.size(); ++i)
	{
		std::cout << copyArray[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < copyArray.size(); ++i)
	{
		copyArray[i] += 5;
	}
	std::cout << "copyArray elements after modification: ";
	for (size_t i = 0; i < copyArray.size(); ++i)
	{
		std::cout << copyArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "intArray elements after copyArray modification: ";
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	Array<int> assignArray;
	assignArray = intArray;
	std::cout << "assignArray elements after assignment from intArray: ";
	for (size_t i = 0; i < assignArray.size(); ++i)
	{
		std::cout << assignArray[i] << " ";
	}
	std::cout << std::endl;

	for (size_t i = 0; i < assignArray.size(); ++i)
	{
		assignArray[i] -= 3;
	}
	std::cout << "assignArray elements after modification: ";
	for (size_t i = 0; i < assignArray.size(); ++i)
	{
		std::cout << assignArray[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "intArray elements after assignArray modification: ";
	for (size_t i = 0; i < intArray.size(); ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Test out-of-bounds access
	try
	{
		std::cout << "Accessing intArray[10]: ";
		std::cout << intArray[10] << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	std::cout << "strArray elements: ";
	for (size_t i = 0; i < strArray.size(); ++i)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
