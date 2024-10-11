#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data
{
    int number;
    std::string text;
};

class Serializer
{
public:
    // Serialize: Convert Data* to uintptr_t
    static uintptr_t serialize(Data* ptr);

    // Deserialize: Convert uintptr_t back to Data*
    static Data* deserialize(uintptr_t raw);

private:
    // Private constructor to prevent instantiation
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
};

#endif
