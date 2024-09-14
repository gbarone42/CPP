#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>  // Include this for std::string in C++98
#include <iostream> // For I/O streams in C++98

struct Data {
    int number;
    std::string text;
};

class Serializer {
public:
    static unsigned long serialize(Data* ptr);   // Use unsigned long instead of uintptr_t
    static Data* deserialize(unsigned long raw); // Use unsigned long instead of uintptr_t

private:
    Serializer();  // Private constructor to prevent instantiation
};

#endif
