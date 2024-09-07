#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

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

	 Constructors & Destructor
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	 Getters
	const std::string& getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	 Member functions
	void beSigned(const Bureaucrat& b);

};

 Overloading the insertion (<<) operator for Form
std::ostream& operator<<(std::ostream& out, const Form& f);

#endif
