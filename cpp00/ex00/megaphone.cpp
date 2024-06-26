#include <iostream> //<iostream> is fundamental for performing input and output operations in C++. It provides convenient ways to interact with users via std::cin and std::cout, handle errors with std::cerr, and perform logging with std::clog.
#include <cctype> // for std::toupper()

int main(int argc, char *argv[])
{
    if (argc <= 1)//check if it's just the program name
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    else
    {
        for (int i = 1; i < argc; ++i)//Iterates through each command-line argument starting from index 1 (argv[1]), skipping the program name (argv[0]).
        {
            for (char *ptr = argv[i]; *ptr != '\0'; ++ptr)//Iterates through each character of the current argument (argv[i]).
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



/*

for (initialization; condition; update)
{
    // Code to be executed repeatedly
}

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