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

    void addContact(const Contact &contact) //The const qualifier ensures that the contact object cannot be modified within this method.
	{//addContact: Adds a new contact to the phone book. It uses the modulo operator % to wrap around if currentContactIndex exceeds 7, effectively using the array as a circular buffer. This ensures that once the array is full, adding new contacts will overwrite the oldest contact
        contacts[currentContactIndex % 8] = contact; //uses the modulo operator (%) to wrap around the index if currentContactIndex exceeds 7, making the contacts array behave like a circular buffer.
        ++currentContactIndex;// variable that keeps track of how many contacts have been added.
    }
	//displayContacts: Prints a formatted table header, then iterates through the contacts array up to currentContactIndex (or 8, whichever is smaller), printing each contact's details. Output formatting is handled using std::setw to ensure alignment.
    void displayContacts() const
    { // Prints column headers for the contact list.
        std::cout << std::setw(10) << "Index" << "|";//std::setw(10): This function, from the <iomanip> header, sets the width of the next printed field to 10 characters. This ensures that each column has uniform width, leading to neatly aligned tables in the console output.
        std::cout << std::setw(10) << "First Name" << "|";
        std::cout << std::setw(10) << "Last Name" << "|";
        std::cout << std::setw(10) << "Nickname" << std::endl;

        int displayCount = currentContactIndex < 8 ? currentContactIndex : 8; //This line calculates how many contacts to display. If the currentContactIndex (the number of contacts added so far) is less than 8, it uses that number. Otherwise, it uses 8, which is the capacity of the contacts array. This ensures that only valid entries are considered for display.
        for (int i = 0; i < displayCount; ++i)
        {
            std::cout << std::setw(10) << i << "|";//std::setw(10) << i: Displays the index of each contact, ensuring it occupies 10 characters width.
            std::cout << std::setw(10) << truncate(contacts[i].getFirstName(), 10) << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getLastName(), 10) << "|";
            std::cout << std::setw(10) << truncate(contacts[i].getNickname(), 10) << std::endl;
        }//Getters (getFirstName(), getLastName(), getNickname()): These functions retrieve the respective fields from each Contact object. The retrieved values are then passed to the truncate() function to ensure they fit within the column width.
    }
//displayContactDetail: Displays detailed information for a contact at a given index. It first checks if the index is valid (within the range of added contacts). If not, it prints an error message.
    void displayContactDetail(int index) const
    {
        if (index < 0 || index >= (currentContactIndex < 8 ? currentContactIndex : 8))
        {
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
    std::string truncate(const std::string& str, size_t width) const
    {
        if (str.length() > width)
        {
            return str.substr(0, width - 1) + ".";
        }
        else
        {
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

/*
First contact at 0 % 8 = 0
Second contact at 1 % 8 = 1
Third contact at 2 % 8 = 2
Fourth contact at 3 % 8 = 3
Fifth contact at 4 % 8 = 4
Sixth contact at 5 % 8 = 5
Seventh contact at 6 % 8 = 6
Eighth contact at 7 % 8 = 7
At this point, each slot in the array is filled with the first set of contacts, indexed from 0 to 7.

Overwriting Begins (Circular Buffer in Action):
Ninth contact at 8 % 8 = 0 (overwrites the first contact)
Tenth contact at 9 % 8 = 1 (overwrites the second contact)
Eleventh contact at 10 % 8 = 2 (overwrites the third contact)
Twelfth contact at 11 % 8 = 3 (overwrites the fourth contact)
Thirteenth contact at 12 % 8 = 4 (overwrites the fifth contact)
Fourteenth contact at 13 % 8 = 5 (overwrites the sixth contact)
Fifteenth contact at 14 % 8 = 6 (overwrites the seventh contact)
Sixteenth contact at 15 % 8 = 7 (overwrites the eighth contact)
Continued Addition:
Seventeenth contact at 16 % 8 = 0 (starts a new cycle of overwriting, beginning again with the first contact)
Eighteenth contact at 17 % 8 = 1 (overwrites again at index 1)
Nineteenth contact at 18 % 8 = 2 (continues overwriting the earlier sequence)
Twentieth contact at 19 % 8 = 3 (and so on..

*/