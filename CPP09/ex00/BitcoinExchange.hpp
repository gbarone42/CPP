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

    /*
    
        
    BitcoinExchange();
    BitcoinExchange(const std::string& csvFile); //
    BitcoinExchange(const BitcoinExchange& other); // Copy constructor
    BitcoinExchange& operator=(const BitcoinExchange& other); // Copy assignment operator
    ~BitcoinExchange();

    */
};

#endif
