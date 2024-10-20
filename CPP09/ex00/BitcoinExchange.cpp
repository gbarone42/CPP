#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string& databaseFile)
{
    std::ifstream file(databaseFile);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    
    std::string line;
    while (getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        double value;

        if (getline(ss, date, ',') && ss >> value)
        {
            prices[date] = value;
        }
    }
}

std::string BitcoinExchange::findNearestDate(const std::string& date)
{
    std::map<std::string, double>::iterator it = prices.lower_bound(date);
    if (it != prices.end())
    {
        --it; // Move to the nearest lower date
        return it->first;
    }
    return ""; // No valid date found
}

bool BitcoinExchange::isValidValue(double value)
{
    return value >= 0 && value <= 1000;
}

void BitcoinExchange::processFile(const std::string& inputFile)
{
    std::ifstream file(inputFile);
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    
    // Skip the header line
    getline(file, line);

    while (getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        double value;

        if (getline(ss, date, '|') && ss >> value)
        {
            // Trim whitespace from date
            date.erase(0, date.find_first_not_of(' ')); // trim left
            date.erase(date.find_last_not_of(' ') + 1); // trim right

            // Check if the value is valid
            if (!isValidValue(value))
            {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }

            std::string nearestDate = findNearestDate(date);
            if (!nearestDate.empty())
            {
                std::cout << date << " => " << value << " = "
                          << value * prices[nearestDate] << std::endl;
            } else
            {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        } else
        {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}
