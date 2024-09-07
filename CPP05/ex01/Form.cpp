#include "Form.hpp"

 Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

 Copy constructor
Form::Form(const Form& other)
	: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

 Assignment operator
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
		 Les autres attributs constants ne peuvent pas être modifiés
	}
	return *this;
}

 Destructor
Form::~Form() {}

 Getters
const std::string& Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

 Member function to sign the form
void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

 Overload the << operator
std::ostream& operator<<(std::ostream& out, const Form& f) {
	out << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", grade required to sign: " << f.getGradeToSign()
		<< ", grade required to execute: " << f.getGradeToExecute();
	return out;
}
