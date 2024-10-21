#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Helper function to check for leap years
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Helper function to validate the date
bool isValidDate(const std::string& date)
{
    int year, month, day;
    char dash1, dash2;

    // Parse the date string (expected format: YYYY-MM-DD)
    std::istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
    {
        return false; // Invalid format
    }

    // Check valid year, month, and day ranges
    if (year < 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }

    // Check the maximum number of days in each month
    if (month == 2)
    {
        // February
        if (isLeapYear(year))
        {
            return day <= 29;
        } else
        {
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        // April, June, September, November have 30 days
        return day <= 30;
    } else
    {
        // All other months have 31 days
        return day <= 31;
    }
}


/*
// Helper function to check for leap years
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Helper function to validate the date
bool isValidDate(const std::string& date)
{
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
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            if (day < 1 || day > 29) return false;
        } else
        {
            if (day < 1 || day > 28) return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        // April, June, September, November have max 30 days
        if (day < 1 || day > 30) return false;
    } else
    {
        // All other months have max 31 days
        if (day < 1 || day > 31) return false;
    }

    return true;
}*/

BitcoinExchange::BitcoinExchange(const std::string& csvFile)
{
    std::ifstream file(csvFile);
    std::string line, date;
    float price;

    while (getline(file, line))
    {
        std::stringstream ss(line);
        getline(ss, date, ',');
        ss >> price;
        priceMap[date] = price;
    }

    file.close();
}

void BitcoinExchange::calculateValue(const std::string& input)
{
    std::stringstream ss(input);
    std::string date;
    float value;
    
    if (getline(ss, date, '|') && (ss >> value))
    {
        // Trim date and check if it is valid
        date.erase(date.find_last_not_of(" \n\r\t")+1); // Trim whitespaces
        if (!isValidDate(date))
        {
            std::cerr << "Error: wrong date." << std::endl;
            return;
        }

         // Check if date is before 2009-01-02
        if (date < "2009-01-02")
        {
            std::cerr << "ERROR: " <<date <<" database starts 2009-01-02, Blockchain network launched in early 2009. ps Satoshi Nakamoto is Hal Finney." << std::endl;
            return;
        }

        // Check if date is before 2022-03-29
        if (date > "2022-03-29")
        {
            std::cerr << "ERROR: " << date << " database ends 2022-03-29, anyway BTC will go to the moon." << " According to database " << date << " is in the future" << std::endl;
            return;
        }

        // Check if value is in range
        if (value < 0)
        {
            std::cerr << "Error: negative." << std::endl;
            return;
        } else if (value > 1000)
        {
            std::cerr << "Error: over 1000." << std::endl;
            return;
        }

        // Find the closest lower or equal date in the database
        std::map<std::string, float>::iterator it = priceMap.lower_bound(date);
        if (it != priceMap.begin() && it->first != date)
            --it;
        
        if (it != priceMap.end())
        {
            float result = it->second * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } else
        {
            std::cerr << "Error: no data for date: " << date << std::endl;
        }
    } else
    {
        std::cerr << "Error: invalid input format." << std::endl;
    }
}
