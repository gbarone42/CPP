#include "Serializer.hpp"

unsigned long Serializer::serialize(Data* ptr) {
    return reinterpret_cast<unsigned long>(ptr);  // Convert pointer to unsigned long
}

Data* Serializer::deserialize(unsigned long raw) {
    return reinterpret_cast<Data*>(raw);  // Convert unsigned long back to pointer
}
