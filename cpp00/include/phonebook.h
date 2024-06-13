#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"
#include <iostream>
#include <iomanip> // For std::setw and std::setfill

class PhoneBook {
private:
    Contact contacts[8];  // Plain C-style array
    int currentContactIndex;

public:
    PhoneBook() : currentContactIndex(0) {}

    void addContact(const Contact &contact) {
        contacts[currentContactIndex % 8] = contact;
        ++currentContactIndex;
    }

    void displayContacts() const {
        std::cout << std::setw(10) << "Index" << "|";
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
    std::string truncate(const std::string& str, size_t width) const {
        if (str.length() > width) {
            return str.substr(0, width - 1) + ".";
        } else {
            return str;
        }
    }
};

#endif // PHONEBOOK_H
