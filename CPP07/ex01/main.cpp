#include <iostream>
#include "iter.hpp"


/*
// A sample function to be applied to each element of the array
void printElement(int &element)
{
    std::cout << element << " ";
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6 , 7 , 7};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Array elements: ";
    iter(arr, length, printElement);
    std::cout << std::endl;

    return 0;
}
*/


int main()
{
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}