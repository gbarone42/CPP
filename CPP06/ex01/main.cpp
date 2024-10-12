
#include "Serializer.hpp"
#include <iostream>

int main()
{
    // Original Data
    Data originalData;
    originalData.number = 42;
    originalData.text = "Hello, Serialization!";

    std::cout << "Original Data: " << std::endl;
    std::cout << "Number: " << originalData.number << std::endl;
    std::cout << "Text: " << originalData.text << std::endl;

    // Serialize: Convert Data* to uintptr_t //special unsigned integer type in C++ capable of holding pointer values
    uintptr_t raw = Serializer::serialize(&originalData);

    // Deserialize: Convert uintptr_t back to Data*
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "\nDeserialized Data: " << std::endl;
    std::cout << "Number: " << deserializedData->number << std::endl;
    std::cout << "Text: " << deserializedData->text << std::endl;

    //se puntano allo stesso indirizzo
    if (&originalData == deserializedData)
    {
        std::cout << "\nSuccess: addresses matches the original!" << std::endl;
    }
    else
    {
        std::cout << "\n FAIL !" << std::endl;
    }

    //check dell'indirizzo bufu
    std::cout << "\n \nMemory Address of originalData: " << std::hex << &originalData << std::endl;
    std::cout << "Memory Address of deserializedData: " << std::hex << deserializedData << std::endl;
    std::cout << "\n \n wow " << std::endl;


    return 0;
}



//The goal is to convert the memory address of a Data structure (i.e., a pointer to Data) to an integer type
//and then convert that integer back to a pointer.

// Serialize (convert pointer to integer)
// Deserialize (convert integer back to pointer)