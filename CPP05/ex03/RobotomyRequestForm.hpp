#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string& target);
	virtual ~RobotomyRequestForm();

	void execute(const Bureaucrat& executor) const;
};

#endif
