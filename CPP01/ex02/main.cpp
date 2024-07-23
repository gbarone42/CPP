#include <iostream>
#include <string>


int main()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

//output memory address
    std::cout << "Address of the string variable: " << &brain << std::endl; //shows where the 'brain' string is stored in memory
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl; // it directly contains the address of brain, so printing stringPTR directly gives the address 
    std::cout << "Address held by stringREF: " << &stringREF << std::endl; //a reference is essentially another name for the same memory location.
//output values
    std::cout << "Value of the string variable: " << brain << std::endl;//direct access
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;//accesses the value at the address stored in the pointer.
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;//direct access

    return 0;
}




//manipulating and understanding references and pointers
//The goal is to write a program that uses a string variable and two ways to refer to it: a pointer and a reference. 
/*
int main()
{
    std::string brain = "HI THIS IS BRAIN"; //string variable //brain is directly initialized as a string //The & operator is used to get the address of brain//stringPTR now holds the memory address where the brain string is stored.
    std::string* stringPTR = &brain; // pointer to the string //pointer that stores the address of brain string
    std::string& stringREF = brain; //reference to the string //A reference is an alias for another variable, meaning stringREF and brain refer to the same memory location.

//output memory address
    std::cout << "Address of the string variable: " << &brain << std::endl; //shows where the 'brain' string is stored in memory
    std::cout << "Address held by stringPTR: " << stringPTR << std::endl; // it directly contains the address of brain, so printing stringPTR directly gives the address // already points at &brain
    std::cout << "Address held by stringREF: " << &stringREF << std::endl; //Also shows the same address, illustrating that a reference is essentially another name for the same memory location.
//output values
    std::cout << "Value of the string variable: " << brain << std::endl;//direct access
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;//Accesses the value at the address stored in the pointer.
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;//direct access

    return 0;
}
*/

//'References' are a powerful feature that provides an alternative name for a variable.
//Unlike pointers, which are variables that store memory addresses of other variables, references are aliases for existing variables.
//Alias Creation: stringREF becomes another name for brain. Any operations performed on stringREF are actually performed on brain.
//Once initialized, stringREF cannot be made to refer to another std::string or another variable. It will always refer to brain.
// Accessing stringREF is like accessing brain directly. There are no extra steps or dereferencing needed, unlike with pointers.




/*


Pointer (stringPTR):

-Stores the address of the brain variable.
-Can be dereferenced using the * operator to access the value it points to.


Reference (stringREF):

-Acts as an alias for the brain variable.
-Directly refers to the same memory location as brain.
-No need to dereference; accessing stringREF is the same as accessing brain.
*/