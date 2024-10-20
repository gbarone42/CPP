#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <chrono>

class PmergeMe {
public:
    void sort(const std::vector<int>& input);
    void sort(const std::list<int>& input);
    void printSorted() const;

private:
    std::vector<int> sortedVector;
    std::list<int> sortedList;

    void mergeInsertionSort(std::vector<int>& vec);
    void mergeInsertionSort(std::list<int>& lst);
};

#endif
