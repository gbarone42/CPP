// ShrubberyCreationForm.cpp
#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    // Convert std::string to const char* using .c_str()
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    ofs << "       _-_       " << std::endl;
    ofs << "    /~~   ~~\\    " << std::endl;
    ofs << " /~~         ~~\\ " << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  / " << std::endl;
    ofs << "   ~  \\\\ //  ~   " << std::endl;
    ofs << "_- -   | | _- _  " << std::endl;
    ofs << "  _ -  | |   -_  " << std::endl;
    ofs << "       // \\\\     " << std::endl;
    ofs.close();
}