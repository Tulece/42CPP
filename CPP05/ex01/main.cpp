#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat john("John", 2);
		Form formA("FormA", 3, 5);
		std::cout << formA << std::endl;

		john.signForm(formA);  // John should sign this successfully
		std::cout << formA << std::endl;

		Bureaucrat alice("Alice", 4);
		Form formB("FormB", 3, 5);
		std::cout << formB << std::endl;

		alice.signForm(formB);  // Alice's grade is too low, should throw exception
		std::cout << formB << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
