#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(const std::string& target);
	virtual ~PresidentialPardonForm();

	void execute(const Bureaucrat& executor) const;
};

#endif
