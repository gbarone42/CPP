#include <iostream>
#include <string>
//manipulating and understanding references and pointers
//The goal is to write a program that uses a string variable and two ways to refer to it: a pointer and a reference. 
int main()
{
    std::string brain = "HI THIS IS BRAIN"; //string variable //brain is directly initialized as a string
    std::string* stringPTR = &brain; // pointer to the string //pointer that stores the address of brain string
    std::string& stringREF = brain; //reference to the string 


    std::cout << "Address of the string variable: " << &brain << std::endl; //shows where the 'brain' string is stored in memory
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl; // it directly contains the address of brain, so printing stringPTR directly gives the address // already points at &brain
    std::cout << "Address held by stringREF: " << &stringREF << std::endl; //Also shows the same address, illustrating that a reference is essentially another name for the same memory location.

    std::cout << "Value of the string variable: " << brain << std::endl;//direct access
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;//Accesses the value at the address stored in the pointer.
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;//direct access

    return 0;
}


//'References' are a powerful feature that provides an alternative name for a variable.
//Unlike pointers, which are variables that store memory addresses of other variables, references are aliases for existing variables.
//Alias Creation: stringREF becomes another name for brain. Any operations performed on stringREF are actually performed on brain.
//Once initialized, stringREF cannot be made to refer to another std::string or another variable. It will always refer to brain.
// Accessing stringREF is like accessing brain directly. There are no extra steps or dereferencing needed, unlike with pointers.