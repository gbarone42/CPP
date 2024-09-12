// main.cpp
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try
    {
        Bureaucrat b1("Alice", 1);
        Form f1("Form A", 3, 5);

        std::cout << b1 << std::endl;
        std::cout << f1 << std::endl;

        b1.signForm(f1);

        std::cout << f1 << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Bob", 80);
        Form f2("Form B", 50, 75);

        std::cout << b2 << std::endl;
        std::cout << f2 << std::endl;

        b2.signForm(f2);

        std::cout << f2 << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
