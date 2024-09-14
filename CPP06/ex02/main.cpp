#include "functions.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
	srand(static_cast<unsigned int>(time(NULL))); // Initialisation du générateur de nombres aléatoires

	Base* basePtr = generate();

	std::cout << "Identifying by pointer: ";
	identify(basePtr);

	std::cout << "Identifying by reference: ";
	identify(*basePtr);

	delete basePtr;

	return 0;
}
