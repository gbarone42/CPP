#include "PmergeMe.hpp"

void PmergeMe::sort(const std::vector<int>& input)
{
    std::vector<int> vec = input;
    // Use traditional timing method without auto
    clock_t start = clock();
    mergeInsertionSort(vec);
    clock_t end = clock();
    
    sortedVector = vec;

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
              << elapsed << " us" << std::endl;
}

void PmergeMe::sort(const std::list<int>& input)
{
    std::list<int> lst = input;
    clock_t start = clock();
    mergeInsertionSort(lst);
    clock_t end = clock();
    
    sortedList = lst;

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6; // Convert to microseconds
    std::cout << "Time to process a range of " << std::distance(lst.begin(), lst.end()) << " elements with std::list: " 
              << elapsed << " usainbolt!" << std::endl;
}

void PmergeMe::printSorted() const
{
    std::cout << "Sorted vector: ";
    // Replace range-based for loop with traditional for loop
    for (size_t i = 0; i < sortedVector.size(); ++i)
	{
        std::cout << sortedVector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted list: ";
    // Use an iterator to print the sorted list
    for (std::list<int>::const_iterator it = sortedList.begin(); it != sortedList.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeInsertionSort(std::vector<int>& vec)
{
    // Insertion Sort for small sections
    for (size_t i = 1; i < vec.size(); i++)
	{
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key)
		{
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = key;
    }
}

void PmergeMe::mergeInsertionSort(std::list<int>& lst)
{
    // Insertion Sort for small sections
    for (std::list<int>::iterator it = ++lst.begin(); it != lst.end(); ++it)
	{
        int key = *it;
        std::list<int>::iterator j = it;
        while (j != lst.begin() && *(--j) > key)
		{
            std::iter_swap(j, it);
            it = j;
        }
        *it = key;
    }
}
