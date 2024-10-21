#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    // Skip the first line (date | value)
    std::string headerLine;
    getline(inputFile, headerLine);

    BitcoinExchange exchange("data.csv");
    std::string line;

    while (getline(inputFile, line)) {
        exchange.calculateValue(line);
    }

    inputFile.close();
    return 0;
}
