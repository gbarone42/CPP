// Form.cpp
#include "Form.hpp"

// Constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), signedStatus(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
    {
    if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw GradeTooHighException();
    }
    else if (gradeToSign > 150 || gradeToExecute > 150)
    {
        throw GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form &other)
    : name(other.name), signedStatus(other.signedStatus), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

// Assignment operator
Form& Form::operator=(const Form &other) {
    if (this != &other) {
        this->signedStatus = other.signedStatus;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const {
    return name;
}

bool Form::isSigned() const {
    return signedStatus;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

// Sign the form
void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > gradeToSign)
    {
        throw GradeTooLowException();
    }
    signedStatus = true;
}

// Exception messages// 'what' method is typically overridden in custom exceptions to return a meaningful explaination of the error, 'what' std::exception class
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low!";
}

// Overload << operator
std::ostream& operator<<(std::ostream &out, const Form &f) {
    out << "Form: " << f.getName() << ", signed: " << (f.isSigned() ? "Yes" : "No")
        << ", grade to sign: " << f.getGradeToSign() << ", grade to execute: " << f.getGradeToExecute();
    return out;
}
