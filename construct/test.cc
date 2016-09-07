#include <cstdio>

class A {
public:
    A() : a_(0) {}
    A(int x) : a_(x) {}
    virtual ~A() {}
    void print() {
        printf("get a_ is %d\n", a_);
    }
private:
    int a_;
};

class B : public A {
public:
    B(int x, int y):A(x+y) {}
    virtual ~B() final {}
};

int main() {
    B b = B(1);
    b.print();
    return 0;
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
