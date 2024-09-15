#include "Intern.hpp"
#include <iostream>

//in exercises 00, 01, and 02, objects like Bureaucrat and Form were created using automatic (stack) allocation
// HELPER FUNCTIONS FOR makeForm
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
    // Array of form names : il goal of the function is to match the input formName with one of the naes in the array
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    // Array of function pointers, where each function pointer points to a function that creates specific form
    AForm* (*formCreators[])(const std::string &target) = {
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };

    // Iterate over form names and check if the formName matches
    for (int i = 0; i < 3; ++i)
    {
        if (formNames[i] == formName)//formNames[0], formNames[1], formNames[2] is compared to the formName 
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);  //the function is called with the target as argument
        }
    }

    throw FormNotFoundException();
}

// Exception message for form not found
const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found!";
}
