// Bureaucrat.hpp
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
public:
//member functionssss
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();
//nested class
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
//nested class
    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    //exceptions

private:
    const std::string name;
    int grade;
};
//
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif
