#include <iostream>
#include <cctype>

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            for (char *ptr = argv[i]; *ptr != '\0'; ++ptr)
            {
                std::cout << static_cast<char>(std::toupper(*ptr));//toupper restituisce un int invece che un char, quindi il cast serve a riconvertire esplicitamente l'int in char
            }
            std::cout << " ";
        }
        std::cout << '\n';
    }
    return 0;
}


/*
#include <iostream> //<iostream> is fundamental for performing input and output operations in C++. It provides convenient ways to interact with users via std::cin and std::cout, handle errors with std::cerr, and perform logging with std::clog.
#include <cctype> // for std::toupper()

int main(int argc, char *argv[])
{
    if (argc <= 1)//check if it's just the program name
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
    }
    else
    {
        for (int i = 1; i < argc; ++i)//Iterates through each command-line argument starting from index 1 (argv[1]), skipping the program name (argv[0]).
        {
            for (char *ptr = argv[i]; *ptr != '\0'; ++ptr)//Iterates through each character of the current argument (argv[i]).
           //dichiaro un puntatore a char
           //char *ptr = argv[i]; initializes ptr to point to the beginning of the C-style string stored in argv[i]. It allows you to manipulate or inspect the characters of the command-line argument argv[i] using pointer arithmetic or dereferencing,
            {
                std::cout << static_cast<char>(std::toupper(*ptr));//std::toupper(*ptr): Converts the current character (*ptr) to uppercase using std::toupper()
            }//std::cout << static_cast<char>(std::toupper(*ptr));: Outputs the uppercase character to standard output.
            //The static_cast<char> is used to convert the int returned by std::toupper(*ptr) back to char before it is passed to std::cout.
            //This conversion ensures that the output operation (std::cout << ...;) correctly interprets the character as a char type, which is expected by std::cout.
            std::cout << " "; // Separate arguments with space
        }
        std::cout << '\n';//Outputs a newline character at the end to ensure the output ends with a newline.
    }//std::endl is a manipulator in C++ that ends the current line of output ('\n') and flushes the output buffer.
    return 0;
}
*/
/*

for (initialization; condition; update)
{
    // Code to be executed repeatedly
}


In the context of the for loop, both ++i and i++ will behave the same way because the increment operation is separate from the loop body.


Initialization: This part is executed once at the beginning of the loop. It initializes a loop control variable or variables. It can declare variables that are used as loop counters.
Condition: This is the condition that is evaluated before each iteration of the loop. If the condition evaluates to true, the loop continues executing; if it evaluates to false, the loop terminates.
Update: This part is executed after each iteration of the loop, typically to update the loop control variable. It increments or decrements the loop counter, moving the loop closer to termination
Code Block: This is the body of the loop where the actual statements or operations to be repeated are placed. It is enclosed in curly braces {}.

*/

/*

In this example, argv would be:
argv[0] = "./program"
argv[1] = "argument1"
argv[2] = "argument2"
argc would be 3 (including the program name).

*/

/*

In C++ (and C), the std::toupper function expects an int as its argument, which represents the character to be converted to uppercase

*/

/*
When you pass a char or a char* to std::toupper, the char is implicitly converted to int. This conversion is safe because characters are essentially represented as integers in their ASCII form
*ptr dereferences the pointer ptr, giving you the character it points to
In summary, while std::toupper technically expects an int, it can accept a char (or char through a pointer)
due to implicit type conversion. This is safe because characters are internally represented as integers (ASCII values),
and std::toupper performs the necessary conversion to uppercase and returns the corresponding ASCII value.
The static_cast<char> in your code ensures thatthe result is properly converted back to char before it's passed 
to std::cout for output, ensuring correct character display.

*/

/*

Suppose you run a program ./myprogram arg1 arg2. Inside the program:

argc would be 3 (including the program name).
argv[0] points to "./myprogram".
argv[1] points to "arg1".
argv[2] points to "arg2".

When i = 1, argv[i] is "arg1".
ptr is initialized to argv[i], so ptr initially points to the first character of "arg1", which is 'a'.
The inner loop then iterates over each character (*ptr) in "arg1" until it reaches '\0' (end of string).

*/



/*

and instance is a predefined object provided by some library

*/


/*


std is a namespace.
std::cout is an object of the std::ostream class within the std namespace.
<< is the stream insertion operator, which is overloaded in the std::ostream class to handle various types of data (like strings, characters, integers, etc.).


An overloaded operator is a function that provides a custom implementation of an operator for user-defined types.
This function is defined in the class and can be used to perform operations on objects of that class.

Overloaded Operator: A function that customizes the behavior of an operator for user-defined types.
*/