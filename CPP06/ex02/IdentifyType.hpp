#ifndef IDENTIFYTYPE_HPP
#define IDENTIFYTYPE_HPP

#include <iostream>
#include <cstdlib>
//#include <ctime> nel mac non servivano
//#include <exception>


class Base {
public:
    virtual ~Base() {}
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
