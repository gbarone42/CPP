// AForm.cpp
#include "AForm.hpp"

// Constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
AForm::AForm(const AForm &other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Assignment operator
AForm& AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->signedStatus = other.signedStatus;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
std::string AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

// Sign the form
void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > gradeToSign) {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const AForm &f) {
    out << "Form: " << f.getName() << ", signed: " << (f.isSigned() ? "Yes" : "No")
        << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
