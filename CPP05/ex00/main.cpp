#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat john("John", 1);
		std::cout << john << std::endl;

		std::cout << "Incrementing John's grade..." << std::endl;
		john.incrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 150);
		std::cout << alice << std::endl;

		std::cout << "Decrementing Alice's grade..." << std::endl;
		alice.decrementGrade();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bob("Bob", 151);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
