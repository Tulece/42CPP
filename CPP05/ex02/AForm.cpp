#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Intern someRandomIntern;
	AForm* rrf;

	 Test creating a RobotomyRequestForm
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf) {
		Bureaucrat john("John", 1);
		john.signForm(*rrf);   Dereference the pointer to pass a reference
		john.executeForm(*rrf);   Dereference the pointer to pass a reference
		delete rrf;
	}

	 Test creating a ShrubberyCreationForm
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "home");
	if (scf) {
		Bureaucrat alice("Alice", 1);
		alice.signForm(*scf);   Dereference the pointer
		alice.executeForm(*scf);   Dereference the pointer
		delete scf;
	}

	 Test creating a PresidentialPardonForm
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "TargetName");
	if (ppf) {
		Bureaucrat bob("Bob", 1);
		bob.signForm(*ppf);   Dereference the pointer
		bob.executeForm(*ppf);   Dereference the pointer
		delete ppf;
	}

	 Test with an invalid form name
	AForm* invalidForm = someRandomIntern.makeForm("invalid form", "TargetName");
	if (!invalidForm) {
		std::cout << "No form was created for invalid form name." << std::endl;
	}

	return 0;
}
