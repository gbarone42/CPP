#include "phonebook.h"
#include <iostream>
#include <string>
#include <sstream>//For std::istringstream

int main() {
    PhoneBook phoneBook;//crea un'istanza della classe phonebook... declaring a variable named phonebook
    std::string command;//dichiarazione di una variabile per contenere i comandi in input

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, or EXIT): ";//output di un prompt che chiede un comando
        std::getline(std::cin, command);//legge una linea dallo standard input sulla variabile 'command'
		//command will contain exactly what was typed by the user without the trailing newline character.
        if (command == "EXIT")
		{
            break;
        }
		else if (command == "ADD")
		{
            Contact contact; //un nuovo oggetto contact è creato
            std::string input; // input field for a new contact

			//prompt the user
			//read the input
			//sets the respective property of the Contact object using setter methods 

            std::cout << "First name: ";
            std::getline(std::cin, input);
            contact.setFirstName(input);

            std::cout << "Last name: ";
            std::getline(std::cin, input);
            contact.setLastName(input);

            std::cout << "Nickname: ";
            std::getline(std::cin, input);
            contact.setNickname(input);

            std::cout << "Phone number: ";
            std::getline(std::cin, input);
            contact.setPhoneNumber(input);

            std::cout << "Darkest secret: ";
            std::getline(std::cin, input);
            contact.setDarkestSecret(input);
			//after all the fiels are filled
            phoneBook.addContact(contact);//the contact is added to phonebook

            std::cout << "Contact added successfully." << std::endl; //confermation for the user
        }
		else if (command == "SEARCH")
		{
            phoneBook.displayContacts();// display list of contact

            std::cout << "Enter index to view details (or type back to return): ";
            std::getline(std::cin, command); //ask user to put a input
            if (command == "back") {
                continue;//If the user types "back", it will skip the remaining steps and continue the loop.
            }

            int index = 0;
            std::istringstream iss(command);//Converts the input string command to an integer index using std::istringstream
            if (!(iss >> index)) {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                continue;
            }

            phoneBook.displayContactDetail(index);
			//Calls displayContactDetail on the PhoneBook instance to show details of the contact at the given index.
        } else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl; //handling invalid commands 
        }
    }

    return 0;
}

//Class: A template or blueprint that defines what attributes and methods its objects will have.
//Object: An instance of a class. Each object of a class has its own identity, and while it shares the structure of the class, it can hold its own state (values of its properties).
//The PhoneBook class likely has a constructor, which is a special type of method that is called automatically when a new object is created. This constructor sets up the initial state of the object, such as initializing its attributes. If no constructor is explicitly defined in the class, the compiler provides a default constructor that initializes the object with default values.