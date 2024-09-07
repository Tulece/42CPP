#include "AForm.hpp"

// Constructor
AForm::AForm(const std::string& name, const std::string& target, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign),
      gradeToExecute(other.gradeToExecute), target(other.target) {}

// Assignment operator
AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
        // The rest of the members are constant and cannot be reassigned
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return target;
}

// Member function to sign the form
void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

// Helper to check if the form can be executed
void AForm::checkExecutable(const Bureaucrat& executor) const {
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

// Overload the << operator
std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
        << ", grade required to sign: " << f.getGradeToSign()
        << ", grade required to execute: " << f.getGradeToExecute()
        << ", target: " << f.getTarget();
    return out;
}
