#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> priceMap;

public:
    BitcoinExchange(const std::string& csvFile);
    void calculateValue(const std::string& input);
};

#endif
