#include <iostream>
#include <cctype> // for std::toupper()

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            for (char *ptr = argv[i]; *ptr != '\0'; ++ptr) {
                std::cout << static_cast<char>(std::toupper(*ptr));
            }
            std::cout << " "; // Separate arguments with space
        }
        std::cout << std::endl;
    }
    return 0;
}