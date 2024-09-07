#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
	const std::string target;

public:
	 Exceptions
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Form grade is too high!";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Form grade is too low!";
			}
	};

	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Form is not signed!";
			}
	};

	 Constructors & Destructor
	AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	 Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	const std::string& getTarget() const;

	 Member functions
	void beSigned(const Bureaucrat& b);
	virtual void execute(const Bureaucrat& executor) const = 0;  Pure virtual function

	 Helper to check if executable
	void checkExecutable(const Bureaucrat& executor) const;
};

 Overload the << operator for AForm
std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
