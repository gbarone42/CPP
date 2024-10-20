#include "PmergeMe.hpp"
#include <sstream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return (1);
    }

    PmergeMe pmergeMe;
    std::vector<int> numbers;
    std::list<int> numberList;

    for (int i = 1; i < argc; ++i)
    {
        try {
            int num = std::stoi(argv[i]);
            if (num < 0)
            {
                std::cerr << "Error: all numbers must be positive integers." << std::endl;
                return 1;
            }
            numbers.push_back(num);
            numberList.push_back(num);
        } catch (const std::invalid_argument& e)
        {
            std::cerr << "Error: invalid number => " << argv[i] << std::endl;
            return 1;
        } catch (const std::out_of_range& e)
        {
            std::cerr << "Error: number out of range => " << argv[i] << std::endl;
            return 1;
        }
    }

    pmergeMe.sort(numbers);
    pmergeMe.sort(numberList);
    pmergeMe.printSorted();

    return 0;
}
