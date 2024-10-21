#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange(const std::string& databaseFile);
    ~BitcoinExchange();

    void processFile(const std::string& inputFile);

private:
    std::map<std::string, double> prices;

    void loadDatabase(const std::string& databaseFile);
    std::string findNearestDate(const std::string& date);
    bool isValidValue(double value);
};

#endif

