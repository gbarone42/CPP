// AForm.hpp
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm& operator=(const AForm &other);
    virtual ~AForm();//The execute() method in the base class (AForm) is pure virtual, meaning that the derived classes (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm) are responsible for implementing the entire execute() logic.

    std::string getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &b);
    virtual void execute(Bureaucrat const &executor) const = 0; // Pure virtual function

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };

private:
    const std::string name;
    bool signedStatus;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream& operator<<(std::ostream &out, const AForm &f);

#endif
