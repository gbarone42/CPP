#include "Serializer.hpp"

// Convert Data* to uintptr_t
uintptr_t Serializer::serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);  // Use reinterpret_cast for pointer-to-integer conversion
}

// Convert uintptr_t back to Data*
Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);  // Use reinterpret_cast for integer-to-pointer conversion
}



//A cast operator in C++ used to convert one pointer type to another, or a pointer to an integer and vice versa.
//It allows you to cast between incompatible types like void* to int or int to void*