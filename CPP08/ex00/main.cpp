#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);

	std::cout << "Testing with non-const std::vector:" << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 20);
		std::cout << "Found value 20 at position: " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 20 not found in vector: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator it = easyfind(vec, 40);
		std::cout << "Found value 40 at position: " << std::distance(vec.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 40 not found in vector: " << e.what() << std::endl;
	}

	const std::vector<int> constVec(vec);

	std::cout << "\nTesting with const std::vector:" << std::endl;

	try
	{
		std::vector<int>::const_iterator it = easyfind(constVec, 30);
		std::cout << "Found value 30 at position: " << std::distance(constVec.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 30 not found in const vector: " << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::const_iterator it = easyfind(constVec, 50);
		std::cout << "Found value 50 at position: " << std::distance(constVec.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 50 not found in const vector: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(100);
	lst.push_back(200);
	lst.push_back(300);

	std::cout << "\nTesting with non-const std::list:" << std::endl;

	try
	{
		std::list<int>::iterator it = easyfind(lst, 200);
		std::cout << "Found value 200 at position: " << std::distance(lst.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 200 not found in list: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::iterator it = easyfind(lst, 400);
		std::cout << "Found value 400 at position: " << std::distance(lst.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 400 not found in list: " << e.what() << std::endl;
	}

	// Testing with const std::list
	const std::list<int> constLst(lst);

	std::cout << "\nTesting with const std::list:" << std::endl;

	try
	{
		std::list<int>::const_iterator it = easyfind(constLst, 100);
		std::cout << "Found value 100 at position: " << std::distance(constLst.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 100 not found in const list: " << e.what() << std::endl;
	}

	try
	{
		std::list<int>::const_iterator it = easyfind(constLst, 500);
		std::cout << "Found value 500 at position: " << std::distance(constLst.begin(), it) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Value 500 not found in const list: " << e.what() << std::endl;
	}

	return 0;
}
