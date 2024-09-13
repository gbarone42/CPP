// main.cpp
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 1);// instanciate object b1 based on bureaucrat class
        std::cout << b1 << std::endl;//operator formats the Bureaucrat object into a string and sends it to the output stream
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
        Bureaucrat b3("Vito", 149);
        std::cout << b3 << std::endl;
        b3.decrementGrade();  //use throw to signal an exception if the grade is invalid
        std::cout << "After decrement, new grade: " << b3 << std::endl;
        b3.incrementGrade();
         std::cout << "After increment, new grade: " << b3 << std::endl;
         b3.decrementGrade();  //use throw to signal an exception if the grade is invalid
         std::cout << "After decrement, new grade: " << b3 << std::endl;
         std::cout << "Testing another decrement"<< std::endl;
         std::cout << "..it is gonna fail.."<< std::endl;
         b3.decrementGrade();  //use throw to signal an exception if the grade is invalid
          //std::cout << "After double decrement, Vito's new grade: " << b3 << std::endl;

    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        Bureaucrat b4("Baffo D'oro", 0);// instanciate object b1 based on bureaucrat class
        std::cout << b4 << std::endl;//operator formats the Bureaucrat object into a string and sends it to the output stream
        b4.incrementGrade();  //use throw to signal an exception if the grade is invalid
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b7("Mario", 75);
        Bureaucrat b8("Luigi", 100);
        std::cout << "Before assignment: " << std::endl;
        std::cout << "b7: " << b7 << std::endl;
        std::cout << "b8: " << b8 << std::endl;

        b7.incrementGrade(); 
        b8 = b7;  // Assignment operator - assigning b7 to b8
        std::cout << "After assignment (b8 = b7): " << std::endl;
        std::cout << "b8: " << b8 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }


     return 0;

}
    /*try
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
*/
   // return 0;
//}
