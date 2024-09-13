#include "Intern.hpp"
#include <iostream>

// Function to create ShrubberyCreationForm
AForm* createShrubberyCreationForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

// Function to create RobotomyRequestForm
AForm* createRobotomyRequestForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

// Function to create PresidentialPardonForm
AForm* createPresidentialPardonForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

// Intern constructor
Intern::Intern() {}

// Copy constructor
Intern::Intern(const Intern &other) {
    (void)other;
}

// Assignment operator
Intern& Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

// Intern destructor
Intern::~Intern() {}

// Function to make forms based on formName
AForm* Intern::makeForm(const std::string &formName, const std::string &target) const {
    // Array of form names
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    // Array of function pointers
    AForm* (*formCreators[])(const std::string &target) = {
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };

    // Iterate over form names and check if the formName matches
    for (int i = 0; i < 3; ++i)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);  // Call the corresponding function
        }
    }

    throw FormNotFoundException();
}

// Exception message for form not found
const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
