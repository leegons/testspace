#include <memory>
#include <iostream>

class Base {
public:
    Base() { std::cout << "Base construct" << std::endl; }
    virtual ~Base() { std::cout << "Base descruct" << std::endl; }
    virtual void print() { std::cout << "Base print" << std::endl; }
};

class A {
public:
    A() { std::cout << "A construct" << std::endl; }
    ~A() { std::cout << "A descruct" << std::endl; }
    virtual void print() { std::cout << "A print" << std::endl; }
};

class B : public Base, A {
public:
    B():Base(),A() { std::cout << "B construct" << std::endl; }
    ~B() { std::cout << "B descruct" << std::endl; }
//    void print() { std::cout << "Base print" << std::endl; }
};

int main() {
    B* p = new B();
    ((Base*)p)->print();
    ((A*)p)->print();
    delete p;
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
