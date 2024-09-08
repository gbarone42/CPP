#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 5);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    // Bob signs and executes Shrubbery Creation Form
    bob.signForm(shrub);
    bob.executeForm(shrub);

    // Alice signs and executes Robotomy and Pardon Forms
    alice.signForm(robot);
    alice.executeForm(robot);

    alice.signForm(pardon);
    alice.executeForm(pardon);

    return 0;
}
