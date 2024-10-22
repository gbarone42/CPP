#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <climits>

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


bool isValidDate(const std::string& date)
{
    int year, month, day;
    char dash1, dash2;


    std::istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-')
    {
        return false;
    }
    if (year < 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }
    if (month == 2)
    {
        if (isLeapYear(year))
        {
            return day <= 29;
        } else
        {
            return day <= 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return day <= 30;
    } else
    {
        return day <= 31;
    }
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile)
{
    std::ifstream file(csvFile);
    std::string line, date;

    float price;//

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
    std::string date, valueString;
    float value;
    
    if (getline(ss, date, '|') && getline(ss, valueString))
    {
        date.erase(date.find_last_not_of(" \n\r\t")+1);
        valueString.erase(0, valueString.find_first_not_of(" \n\r\t"));

        std::stringstream valueStream(valueString);
        std::string firstValue, extraValue;
        valueStream >> firstValue >> extraValue;

        if (!extraValue.empty())
        {


            std::cerr << "Error: wrong format in line \"" << input << "\"" << std::endl;
            return;
        }
        try
        {
            value = std::stof(firstValue); 
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: invalid value format." << std::endl;
            return;
        }

        if (!isValidDate(date)) 
        {
            std::cerr << "Error: wrong date." << std::endl;
            return;

        }



        if (value < 0)
        {
            
            std::cerr << "Error: negative value." << std::endl;
            return;
        } 
        else if (value > 1000)
        {
            std::cerr << "Error: value exceeds 1000." << std::endl;
            return;
        }
        std::map<std::string, float>::iterator it = priceMap.lower_bound(date);
        if (it != priceMap.begin() && it->first != date)
            --it;

        if (it != priceMap.end())
        {
            float result = it->second * value;
            std::cout << date << " => " << value << " = " << result << std::endl;
        } 
        else
        {
            std::cerr << "Error: no data for date: " << date << std::endl;
        }
    } 
    else 
    {
        std::cerr << "Error: invalid input format." << std::endl;
    }
}

/*
BitcoinExchange::BitcoinExchange() {}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    priceMap = other.priceMap;
}

// Copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
    {
        priceMap = other.priceMap;
    }
    return *this;
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}

*/

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
