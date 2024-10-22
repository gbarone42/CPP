#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <algorithm>

class PmergeMe {
public:

/*
    // Canonical Orthodox Form
    PmergeMe();                                // Default Constructor
    PmergeMe(const PmergeMe& other);            // Copy Constructor
    PmergeMe& operator=(const PmergeMe& other); // Copy Assignment Operator
    ~PmergeMe();  
*/
    void sort(const std::vector<int>& input);
    void sort(const std::list<int>& input);
    void printSorted() const;

private:
    std::vector<int> sortedVector;
    std::list<int> sortedList;

    void fordJohnsonSort(std::vector<int>& vec);
    void fordJohnsonSort(std::list<int>& lst);
    void merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result);
    void merge(std::list<int>& left, std::list<int>& right, std::list<int>& result);
};
#endif
