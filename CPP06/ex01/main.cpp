#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data originalData;
    originalData.number = 42;
    originalData.text = "Hello, Serialization!";

    std::cout << "Original Data: " << std::endl;
    std::cout << "Number: " << originalData.number << std::endl;
    std::cout << "Text: " << originalData.text << std::endl;

    // Use unsigned long instead of uintptr_t
    unsigned long raw = Serializer::serialize(&originalData);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "Number: " << deserializedData->number << std::endl;
    std::cout << "Text: " << deserializedData->text << std::endl;

    // Check if the original and deserialized pointers are equal
    if (&originalData == deserializedData)
    {
        std::cout << "\nSuccess: The deserialized pointer matches the original!" << std::endl;
    }
    else
    {
        std::cout << "\nError: The deserialized pointer does not match the original!" << std::endl;
    }

    return 0;
}
