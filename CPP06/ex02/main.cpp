#include "IdentifyType.hpp"
//#include <ctime> nel mac non servivano
//#include <exception>

int main()
{
    Base* basePtr = generate();

    std::cout << "Identifying via pointer: ";
    identify(basePtr);

    std::cout << "Identifying via reference: ";
    identify(*basePtr);

    delete basePtr;
    return 0;
}
