#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        // Create an intern
        Intern someRandomIntern;

        // Test with valid forms
        std::cout << "\n--- Testing valid form creation ---" << std::endl;
        
        AForm* shrubForm = someRandomIntern.makeForm("shrubbery creation", "home");
        AForm* robotForm = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardonForm = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

        std::cout << *shrubForm << std::endl;
        std::cout << *robotForm << std::endl;
        std::cout << *pardonForm << std::endl;

        // Create Bureaucrats
        Bureaucrat bob("Bob", 138);
        Bureaucrat alice("Alice", 1);

        // Bob signs and executes ShrubberyCreationForm
        //std::cout << "\n--- Bob signs and executes ShrubberyCreationForm ---" << std::endl;
        bob.signForm(*shrubForm);
        bob.executeForm(*shrubForm);

        // Alice signs and executes RobotomyRequestForm
        std::cout << "\n--- Alice signs and executes RobotomyRequestForm ---" << std::endl;
        alice.signForm(*robotForm);
        alice.executeForm(*robotForm);

        // Alice signs and executes PresidentialPardonForm
        std::cout << "\n--- Alice signs and executes PresidentialPardonForm ---" << std::endl;
        alice.signForm(*pardonForm);
        alice.executeForm(*pardonForm);

        // Test with an invalid form
        std::cout << "\n--- Testing invalid form creation ---" << std::endl;
        try
        {
            AForm* invalidForm = someRandomIntern.makeForm("invalid form", "Target");
            delete invalidForm;  // ma tanto non vera' chiamata
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;  // printa"Form not found!"
        }

        // Clean up memory
        delete shrubForm;
        delete robotForm;
        delete pardonForm;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
