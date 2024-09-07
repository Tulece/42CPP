#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", target, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	checkExecutable(executor);
	std::ofstream ofs(getTarget() + "_shrubbery");
	if (ofs.is_open()) {
		ofs << "       _-_       \n"
			<< "    /~~   ~~\\    \n"
			<< " /~~         ~~\\ \n"
			<< "{               }\n"
			<< " \\  _-     -_  / \n"
			<< "   ~  \\\\ //  ~   \n"
			<< "_- -   | | _- _  \n"
			<< "  _ -  | |   -_  \n"
			<< "      // \\\\      \n";
		ofs.close();
	}
}
