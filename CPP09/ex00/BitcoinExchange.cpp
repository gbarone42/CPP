#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <regex>

// Helper function to check for leap years
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Helper function to validate the date
bool isValidDate(const std::string& date) {
    std::regex datePattern(R"((\d{4})-(\d{2})-(\d{2}))");
    std::smatch match;
    
    if (!std::regex_match(date, match, datePattern)) {
        return false;
    }

    int year = std::stoi(match[1].str());
    int month = std::stoi(match[2].str());
    int day = std::stoi(match[3].str());

    // Check valid month
    if (month < 1 || month > 12) {
        return false;
    }

    // Check valid day based on month and leap year for February
    if (month == 2) {
        if (isLeapYear(year)) {
            if (day < 1 || day > 29) return false;
        } else {
            if (day < 1 || day > 28) return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        // April, June, September, November have max 30 days
        if (day < 1 || day > 30) return false;
    } else {
        // All other months have max 31 days
        if (day < 1 || day > 31) return false;
    }

    return true;
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile) {
    std::ifstream file(csvFile);
    std::string line, date;
    float price;

    while (getline(file, line)) {
        std::stringstream ss(line);
        getline(ss, date, ',');
        ss >> price;
        priceMap[date] = price;
    }

    file.close();
}

void BitcoinExchange::calculateValue(const std::string& input) {
    std::stringstream ss(input);
    std::string date;
    float value;
    
    if (getline(ss, date, '|') && (ss >> value)) {
        // Trim date and check if it is valid
        date.erase(date.find_last_not_of(" \n\r\t")+1); // Trim whitespaces
        if (!isValidDate(date)) {
            std::cerr << "Error: wrong date." << std::endl;
            return;
        }

        // Check if value is in range
        if (value < 0) {
            std::cerr << "Error: negative." << std::endl;
            return;
        } else if (value > 1000) {
            std::cerr << "Error: over 1000." << std::endl;
            return;
        }

        // Find the closest lower or equal date in the database
        std::map<std::string, float>::iterator it = priceMap.lower_bound(date);
        if (it != priceMap.begin() && it->first != date)
            --it;
        
        if (it != priceMap.end()) {
            float result = it->second * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } else {
            std::cerr << "Error: no data for date: " << date << std::endl;
        }
    } else {
        std::cerr << "Error: invalid input format." << std::endl;
    }
}
