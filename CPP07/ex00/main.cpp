#include <iostream>
#include "whatever.hpp"

int main(void)
{
    int a = 2;
    int b = 333;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    return 0;
}



//when dealing with strings the concept of minimum and maximum is based on lexicographical order
//the first string that has a character with a smaller ascii value will be the smallest
//ascii value of "1" is 49
//ascii value of "2" is 50


/*
int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}
*/

//Function Templates allow you to create a single function definition 
//that can work with different data types without repeating code for each type.

//Type Deduction: When you call a function template,
//the compiler deduces the type based on the arguments you pass. 