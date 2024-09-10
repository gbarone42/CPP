// main.cpp
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade();  //use throw to signal an exception if the grade is invalid
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade();  //use throw to signal an exception if the grade is invalid
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b3("Charlie", 151);  //
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b4("Dave", 0);  // 
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
        try
    {
        Bureaucrat b5("Simone", 2);
        std::cout << b5 << std::endl;
        b5.incrementGrade();  //
        std::cout << "After incrementing: " << b5 << std::endl;  // Print new value 🔔
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
        try
    {
        Bureaucrat b6("Bruno", 100);
        std::cout << b6 << std::endl;
        b6.decrementGrade();  //
        std::cout << "After decrementing: " << b6 << std::endl;  // Print new value of Bruno 🔔
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
