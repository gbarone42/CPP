// Bureaucrat.cpp
#include "Bureaucrat.hpp"

// Constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}




// Assignment operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
//Bureaucrat::~Bureaucrat() {}
Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << name << " with grade " << grade << " is being destroyed." << std::endl;
}



// Getters
std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

// Increment and Decrement
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
    {
        throw GradeTooHighException();
    }
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
    {
        throw GradeTooLowException();
    }
    grade++;
}

// Exception messages  🔔🔔🔔🔔🔔🔔
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

// Overload << operator  🔔🔔🔔🔔🔔🔔
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
