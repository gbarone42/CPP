#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);
    Bureaucrat charlie("Charlie", 150); // Lowest grade
    Bureaucrat dave("Dave", 145);       // Can sign ShrubberyCreationForm, but not execute it

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

    // Test with Charlie (grade 150), who cannot sign any form due to low grade
    std::cout << "\n--- Testing Charlie (Grade 150) ---" << std::endl;
    charlie.signForm(shrub);  // Should fail
    charlie.executeForm(shrub);  // Should fail (not signed)

    charlie.signForm(robot);  // Should fail
    charlie.executeForm(robot);  // Should fail (not signed)

    charlie.signForm(pardon);  // Should fail
    charlie.executeForm(pardon);  // Should fail (not signed)

    // Test with Dave (Grade 145) - can sign ShrubberyCreationForm but can't execute it
    std::cout << "\n--- Testing Dave (Grade 145) ---" << std::endl;
    dave.signForm(shrub);  // Should succeed
    dave.executeForm(shrub);  // Should fail (not high enough to execute)

    dave.signForm(robot);  // Should fail (too low to sign)
    dave.executeForm(robot);  // Should fail (not signed)

    dave.signForm(pardon);  // Should fail (too low to sign)
    dave.executeForm(pardon);  // Should fail (not signed)

    return 0;
}


/*
int main() {
    Bureaucrat bob("Bob", 50);
    Bureaucrat alice("Alice", 1);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Ford Prefect");

    bob.signForm(shrub);
    bob.executeForm(shrub);

    alice.signForm(robot);
    alice.executeForm(robot);

    alice.signForm(pardon);
    alice.executeForm(pardon);

    return 0;
}
*/