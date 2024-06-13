#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact() {}

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
