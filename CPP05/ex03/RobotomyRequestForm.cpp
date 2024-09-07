#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	checkExecutable(executor);
	std::cout << "* drilling noises *" << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << getTarget() << std::endl;
}
