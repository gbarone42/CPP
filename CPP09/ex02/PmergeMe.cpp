#include "PmergeMe.hpp"

void PmergeMe::sort(const std::vector<int>& input)
{
    std::vector<int> vec = input;//non modificare l'originale //good practice
    clock_t start = clock();
    fordJohnsonSort(vec);
    clock_t end = clock();

    sortedVector = vec;//il risultato copiato nel member class della classe pmerge

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " 
              << elapsed << " usainbolt!" << std::endl;
}

void PmergeMe::sort(const std::list<int>& input)
{
    std::list<int> lst = input;
    
    clock_t start = clock();
    fordJohnsonSort(lst);
    clock_t end = clock();
    
    sortedList = lst;

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1e6; //fino a qui uguale, la dimensione poi si calcola diversamente
    std::cout << "Time to process a range of " << std::distance(lst.begin(), lst.end()) << " elements with std::list: " 
              << elapsed << " usainbolt!" << std::endl;
}

void PmergeMe::printSorted() const
{
    std::cout << "Sorted vector: ";

    for (size_t i = 0; i < sortedVector.size(); ++i)
	{
        std::cout << sortedVector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted list: ";

    for (std::list<int>::const_iterator it = sortedList.begin(); it != sortedList.end(); ++it)
	{//std::list dont have a size method
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fordJohnsonSort(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    std::vector<int> left, right;//lo splitto in due vec
    for (size_t i = 0; i < vec.size(); i += 2)//due alla volta
    {
        if (i + 1 < vec.size())//controllo se sono due o l'ultimo
        {
            if (vec[i] < vec[i + 1])
            {
                left.push_back(vec[i]);//pusho sempre il piu piccolo a sinistra
                right.push_back(vec[i + 1]);
            }
            else
            {
                left.push_back(vec[i + 1]);//pusho sempre il piu piccolo a sinistra
                right.push_back(vec[i]);
            }
        }
        else
        {
            left.push_back(vec[i]);//vuol dire che non c'erano piu coppie
        }
    }



    fordJohnsonSort(left);
    fordJohnsonSort(right);



    std::vector<int> result;
    merge(left, right, result);

    vec = result;
}

void PmergeMe::fordJohnsonSort(std::list<int>& lst)
{
    if (lst.size() <= 1)
        return;

 
    std::list<int> left, right;
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end())
    {
        int first = *it;
        ++it;
        if (it != lst.end())
        {
            int second = *it;
            if (first < second)
            {
                left.push_back(first);
                right.push_back(second);
            }
            else
            {
                left.push_back(second);
                right.push_back(first);
            }
            ++it;
        }
        else
        {
            left.push_back(first);
        }
    }


    fordJohnsonSort(left);
    
    fordJohnsonSort(right);







    std::list<int> result;
    merge(left, right, result);

    lst = result;
}

void PmergeMe::merge(std::vector<int>& left, std::vector<int>& right, std::vector<int>& result)
{
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }
    while (i < left.size())
        result.push_back(left[i++]);
    while (j < right.size())
        result.push_back(right[j++]);
}

void PmergeMe::merge(std::list<int>& left, std::list<int>& right, std::list<int>& result)
{
    std::list<int>::iterator itLeft = left.begin(), itRight = right.begin();
    while (itLeft != left.end() && itRight != right.end())
    {
        if (*itLeft < *itRight)
            result.push_back(*itLeft++);
        else
            result.push_back(*itRight++);
    }
    while (itLeft != left.end())
        result.push_back(*itLeft++);
    while (itRight != right.end())
        result.push_back(*itRight++);
}



/*
// Default Constructor
PmergeMe::PmergeMe() {
    //
}

// Copy Constructor
PmergeMe::PmergeMe(const PmergeMe& other) {

    sortedVector = other.sortedVector;
    sortedList = other.sortedList;
}

// Copy Assignment Operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        
        sortedVector = other.sortedVector;
        sortedList = other.sortedList;
    }
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {
    // No dynamic resources to clean up for now
}*/