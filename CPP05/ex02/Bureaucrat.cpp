#include "Bureaucrat.hpp"

 Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

 Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {}

 Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << *this << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << *this << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << *this << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
