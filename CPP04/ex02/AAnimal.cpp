#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal") {
    std::cout << "Animal created." << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "Animal copied." << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Animal assigned." << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destroyed." << std::endl;
}

std::string AAnimal::getType() const {
    return type;
}
