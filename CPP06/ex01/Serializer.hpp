#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
// nel mac non mi serviva #include <cstdint>  // For uintptr_t

struct Data
{
    int number;
    std::string text;
};

class Serializer
{
public:
    
    static uintptr_t serialize(Data* ptr);

    
    static Data* deserialize(uintptr_t raw);

private:
     // Orthodox Canonical
    Serializer();                                // Default Constructor
    Serializer(const Serializer&);               // Copy Constructor
    Serializer& operator=(const Serializer&);    // Copy Assignment Operator
    ~Serializer();                               // Destructor
};

#endif

/*
// Private Default Constructor (hidden to prevent instantiation)
Serializer::Serializer() {
    // Empty - No need to initialize anything
}

// Private Copy Constructor (hidden to prevent copying)
Serializer::Serializer(const Serializer& other) {
    // Prevent copying - No copying allowed
}

// Private Copy Assignment Operator (hidden to prevent assignment)
Serializer& Serializer::operator=(const Serializer& other) {
    // Prevent assignment - No assignment allowed
    return *this;
}

// Private Destructor (hidden to prevent destruction)
Serializer::~Serializer() {
    // Empty - No resources to clean up
}
*/