#include <iostream>
#include "iter.hpp"




void print(const int& x)
{
    std::cout << x << std::endl;
}

int main()
{
    int tab[] = {0, 1, 2, 3, 4, 5, 6};
    iter(tab, 7, print);
    //iter(tab, 6, print);
    //iter(tab, 8, print);

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