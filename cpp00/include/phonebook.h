#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h" //definition of the Contact class so that PhoneBook can use it.
#include <iostream>// Standard Library's I/O stream that allows output to the console using std::cout
#include <iomanip> // For std::setw

class PhoneBook { //begins the definition of phonebook class, Everything between the curly braces {} defines what this class is and can do.
private:
    Contact contacts[8];  // Plain C-style array holds up to 8 Contact objects //static allocation
    int currentContactIndex; //an integer that keeps track of the number of contacts currently stored and also serves as an index for the next contact to be added.

public:
    PhoneBook() : currentContactIndex(0) {} //Constructor for PhoneBook initializes currentContactIndex to 0, indicating that there are no contacts initially.

    void addContact(const Contact &contact) {//addContact: Adds a new contact to the phone book. It uses the modulo operator % to wrap around if currentContactIndex exceeds 7, effectively using the array as a circular buffer. This ensures that once the array is full, adding new contacts will overwrite the oldest contact
        contacts[currentContactIndex % 8] = contact; //uses the modulo operator (%) to wrap around the index if currentContactIndex exceeds 7, making the contacts array behave like a circular buffer.
        ++currentContactIndex;
    }
	//displayContacts: Prints a formatted table header, then iterates through the contacts array up to currentContactIndex (or 8, whichever is smaller), printing each contact's details. Output formatting is handled using std::setw to ensure alignment.
    void displayContacts() const { // Prints column headers for the contact list.
        std::cout << std::setw(10) << "Index" << "|";//td::setw from <iomanip> for setting the width of each column to ensure proper alignment.
        std::cout << std::setw(10) << "First Name" << "|";
        std::cout << std::setw(10) << "Last Name" << "|";
        std::cout << std::setw(10) << "Nickname" << std::endl;

        int displayCount = currentContactIndex < 8 ? currentContactIndex : 8;
        for (int i = 0; i < displayCount; ++i) {
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getFirstName(), 10) << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getLastName(), 10) << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getNickname(), 10) << std::endl;
        }
    }
//displayContactDetail: Displays detailed information for a contact at a given index. It first checks if the index is valid (within the range of added contacts). If not, it prints an error message.
    void displayContactDetail(int index) const {
        if (index < 0 || index >= (currentContactIndex < 8 ? currentContactIndex : 8)) {
            std::cout << "Invalid index." << std::endl;
            return;
        }
        const Contact &contact = contacts[index];
        std::cout << "First Name: " << contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
    }

private:
//truncate: A utility function used to truncate strings that exceed a given width, appending a period '.' to indicate truncation. This is useful for maintaining column widths in displayContacts.
    std::string truncate(const std::string& str, size_t width) const {
        if (str.length() > width) {
            return str.substr(0, width - 1) + ".";
        } else {
            return str;
        }
    }
};

#endif // PHONEBOOK_H

/*
std::setw(int width)
From <iomanip>, used to set the width of the next input/output field.
Helps align text in the output, making it easy to read in tabular format.

std::cout
From <iostream>, used for standard output streaming (e.g., to print text to the console).

std::endl which is used in conjunction with std::cout
From <iostream>, used to insert a newline character into the output stream and flush the stream.
Flushing the buffer means sending all stored (buffered) output to the intended display device (like a terminal or console) immediately.
*/