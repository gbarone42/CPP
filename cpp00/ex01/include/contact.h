#ifndef CONTACT_H
#define CONTACT_H
//these lines are "include guards", their purpose is to prevent multiple inclusions of the same header 
#include <string> //std::string

class Contact {//begins the definition of contact class

// Making them private enforces encapsulation, one of the core principles of object-oriented programming. 
//Encapsulation ensures that the class's data can only be accessed and modified through its methods,
// protecting it from unintended or harmful modifications by external code.
//
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
//std::string It encapsulates character arrays and provides a wealth of functions that make string manipulation safe and straightforward. It manages its own memory, automatically resizing as needed, and protects against common buffer overflow errors that can occur with C-style strings.
//You can append characters, concatenate strings, and modify strings in various ways without worrying about allocating or deallocating memory—a common source of bugs in C-style string handling.
public:
    Contact() {} //constructor is defined but doesn perform any initialization, provides a default constructor
//It allows for the creation of Contact objects without needing to provide initial values. This is useful when you want to create a Contact object and set its attributes later using setter methods.
//setFirstName metodo:                   //'&' indicates that the parameter is being passed by reference: it means that instead of creating a new copy of the parameter's value for the function to use, the function accesses the original variable directly               
										//The 'const' qualifier is used with a reference to ensure that the function does not alter the variable it references. 
	void setFirstName(const std::string &value) { firstName = value; } //Passing by reference means that the function can access the argument directly without copying it, which is more efficient for large types like strings /// Setter with const & Reference: Ensures that the function does not alter the passed argument, while also benefiting from the performance gain of passing by reference.
    void setLastName(const std::string &value) { lastName = value; }
    void setNickname(const std::string &value) { nickname = value; }
    void setPhoneNumber(const std::string &value) { phoneNumber = value; }
    void setDarkestSecret(const std::string &value) { darkestSecret = value; }
//The const modifier in the parameter declaration prevents the setter from altering the input string
// 'const' assures that the data passed into the method remains unchanged
// '&' denotes that the parameter is passed by reference, meaning that instead of creating a new copy of the input string the method operates directly on the original string that is passed in
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
};
//(const): When you declare a method with const after its parameter list (e.g., std::string getName() const), you are promising that this method will not change the state of the object. This method becomes a read-only method for the object’s state.
//Thread Safety: In multi-threaded applications, const methods are inherently thread-safe when it comes to accessing shared data because they don't modify the shared state. Multiple threads can read from the same object without causing race conditions.
#endif // CONTACT_H

//In your Contact class, the data members such as firstName, lastName, nickname, phoneNumber, and darkestSecret are declared as private. This design choice protects these members from being modified directly by external functions or classes, which helps to maintain valid states and encapsulates the functionality specific to handling contact details.
//The methods like setFirstName, setLastName, and getFirstName are declared as public. These methods provide controlled access to the private data:
//Setter methods are used to modify the state of an object's attributes from outside the class. They are public methods that provide controlled access to private data members.//These methods allow external code to modify the private data in a controlled manner.
//Getter methods provide a way to access private data members' values. They do not modify the object//These provide read access to the private data without allowing it to be modified


//std stands for "standard", it's used to prevent name collisions that can occur especially when your code base includes multiple libraries
//std is the namespace for the Standard C++ Library, and string is a class defined within that namespace. The :: operator tells the compiler that string is a member of the std namespace. This helps avoid naming conflicts by clearly specifying which namespace's member is being referred to.


/*

Efficiency: Using & means the parameter is passed by reference rather than by value.
Passing by reference avoids copying the entire data structure (in this case, a string) to the stack for the function call.
This is particularly important for large data structures like classes or large strings,
where copying can significantly impact performance due to extra memory allocation and data copying operations.
combined with const, this capability to modify is controlled


Safety and Intent: Adding const to a reference parameter (const std::string &) tells the compiler and the programmer that
the function does not intend to modify the data passed to it. This is crucial for functions designed only to read from the
input parameter without altering it.

The combination of const and & in function parameters is a common and recommended practice in C++ for functions that need to access large or complex parameters read-only mode.
The combination ensures that functions receive data efficiently without copying and with a guarantee of not modifying the data.
This is highly beneficial in maintaining performance while also protecting the data passed into functions.
It offers the efficiency of passing by reference with the safety guarantees of const, making functions safer (non-mutating) and faster (non-copying).
*/


//In C++, a class is like a blueprint for creating objects