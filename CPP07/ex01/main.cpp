#include <iostream>
#include "iter.hpp"



// A sample function to be applied to each element of the array
void print(const int& x)
{
    std::cout << x << std::endl; // Print each element
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4, 5, 6}; // Sample array
    iter(tab, 8, print);         // puntatore alla funzione

    return 0;
}

/*
int main()
{
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}
*/