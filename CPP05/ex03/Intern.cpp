#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

AForm* createShrubberyCreationForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// Array of pointers to functions
	AForm* (*formCreators[3])(const std::string&) = {
		createShrubberyCreationForm,
		createRobotomyRequestForm,
		createPresidentialPardonForm
	};

	// Loop through form names to find a match and call the corresponding creation function
	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Error: Form '" << formName << "' does not exist." << std::endl;
	return NULL;
}
