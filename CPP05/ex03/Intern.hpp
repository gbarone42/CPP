// Intern.hpp
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern {
public:
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();

    AForm* makeForm(const std::string &formName, const std::string &target) const;

    class FormNotFoundException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif