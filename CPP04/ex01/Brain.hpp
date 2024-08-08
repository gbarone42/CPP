#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];

public:
    Brain(); // Default Constructor
    Brain(const Brain& other); // Copy Constructor
    Brain& operator=(const Brain& other); // Copy Assignment Operator
    ~Brain(); // Destructor

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};

#endif // BRAIN_HPP
