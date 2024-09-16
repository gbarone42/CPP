// Bureaucrat.cpp
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade < 1)// 1 is the greatest level as a bureaucrat
    {
        throw GradeTooHighException();
    }
    else if (grade > 150)
    {
        throw GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}



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
  //  std::cout << "Bureaucrat " << name << " with grade " << grade << " is being destroyed." << std::endl;
}


// Getters o accessors come lo chiama il correction sheet
std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

// Increment che decrementa l'intero
void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
    {
        throw GradeTooHighException();
    }
    grade--;// sososo increment level of bureaucrat actually means decrease/lower the number
}
// and Decrement che incrementa l'intero
void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
    {
        throw GradeTooLowException();
    }
    grade++;//mmh decrese level of bureaucrat actually means increse/higher the number
}

// Exception messages  🔔🔔🔔🔔🔔🔔
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    //throw 12;
    return "Grade too high!";//could add print messge for when is negative(?)
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!"; //could also add the it over 150
}

// Overload << operator  🔔🔔🔔🔔🔔🔔
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}
// Constructor, a special function to initialize the object created ensuring the object starts in a valid condition