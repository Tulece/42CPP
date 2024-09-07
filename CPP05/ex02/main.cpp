#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	try {
		Bureaucrat john("John", 1);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("target1");
		PresidentialPardonForm pardon("target2");

		john.signForm(shrub);
		john.signForm(robot);
		john.signForm(pardon);

		john.executeForm(shrub);
		john.executeForm(robot);
		john.executeForm(pardon);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
