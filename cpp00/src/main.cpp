#include "phonebook.h"
#include <iostream>
#include <string>
#include <sstream> // For std::istringstream

int main() {
    PhoneBook phoneBook; //crea un'istanza della classe phonebook
    std::string command; //dichiarazione di una variabile per contenere i comandi in input

    while (true) {
        std::cout << "Enter command (ADD, SEARCH, or EXIT): "; //output di un prompt che chiede un comando
        std::getline(std::cin, command); // legge una linea dallo standard input sulla variabile 'command'

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
            phoneBook.displayContacts();

            std::cout << "Enter index to view details (or type back to return): ";
            std::getline(std::cin, command);
            if (command == "back") {
                continue;
            }

            int index = 0;
            std::istringstream iss(command);
            if (!(iss >> index)) {
                std::cout << "Invalid input. Please enter a valid number." << std::endl;
                continue;
            }

            phoneBook.displayContactDetail(index);
        } else {
            std::cout << "Invalid command. Please use ADD, SEARCH, or EXIT." << std::endl;
        }
    }

    return 0;
}
