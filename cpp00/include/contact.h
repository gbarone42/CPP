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

public:
    Contact() {} //constructor is defined but doesn perform any initialization, provides a default constructor

    void setFirstName(const std::string &value) { firstName = value; }
    void setLastName(const std::string &value) { lastName = value; }
    void setNickname(const std::string &value) { nickname = value; }
    void setPhoneNumber(const std::string &value) { phoneNumber = value; }
    void setDarkestSecret(const std::string &value) { darkestSecret = value; }

    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
};

#endif // CONTACT_H


//Setter methods are used to modify the state of an object's attributes from outside the class. They are public methods that provide controlled access to private data members.
//Getter methods provide a way to access private data members' values. They do not modify the object\