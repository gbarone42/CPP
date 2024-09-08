// main.cpp
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* rrf;

    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        Bureaucrat bob("Bob", 50);
        bob.signForm(*rrf);
        bob.executeForm(*rrf);
        delete rrf;
    }

    try {
        AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Target");
        delete invalidForm;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
