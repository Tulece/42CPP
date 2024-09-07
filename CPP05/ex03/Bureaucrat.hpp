#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string name;
	int grade;

public:
	// Exceptions
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too high!";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too low!";
			}
	};

	// Constructors & Destructor
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(AForm& form);

	void executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
