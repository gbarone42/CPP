#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

    BitcoinExchange exchange("input.csv");
    exchange.processFile(argv[1]);

    return 0;
}
